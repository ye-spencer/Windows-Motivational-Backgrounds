/* WMB.cpp
 * Author: Spencer Ye
 * Last Edited: August 2nd, 2024
 * Version: 1.0.1
 */

#include <windows.h>
#include <iostream>
#include <filesystem>
#include <string>
#include <cstdlib>

void setWallpaper(std::string imageName);
std::string pickImage();

int main()
{
    std::string path = pickImage();

    setWallpaper(path);
}

void setWallpaper(std::string imageName)
{
    // Get the current directory path
    char buffer[256];
    GetCurrentDirectoryA(256, buffer);

    // Create the file name that we will be setting and convert into a wstring
    std::string fileName = buffer + imageName;
    std::wstring wideStr = std::wstring(fileName.begin(), fileName.end());
    const wchar_t * finalFileName = wideStr.c_str();

    // Actually set the wallpaper
    SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*) finalFileName, SPIF_UPDATEINIFILE);
}

std::string pickImage()
{
    // Get directory size, unforunately no faster way to go about this
    size_t size = 0;

    for (const auto & entry : std::filesystem::directory_iterator(".\\images"))
    {
        size++;
    }

    // Generate a random seed to generate a random background to set to
    srand(time(0));
    int index = rand() % size;

    // Looping until we get to the one we got
    for (const auto & entry : std::filesystem::directory_iterator(".\\images"))
    {
        // If the index is correct, return it
        if (index == 0)
        {
            return entry.path().string();
        }
        index--;

    }
    return "UNKNOWN ERROR: COULD NOT PICK IMAGE";
}