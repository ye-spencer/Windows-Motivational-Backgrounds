/* WMB.cpp
 * Author: Spencer Ye
 * Last Edited: August 2nd, 2024
 * Version: 1.0.0
 */

#include <windows.h>
#include <iostream>
#include <filesystem>
#include <string>
#include <cstdlib>

bool setWallpaper(std::string imageName);
std::string pickImage();

namespace fs = std::filesystem;

int main()
{
    std::string path = pickImage();

    setWallpaper(path);
}

bool setWallpaper(std::string imageName)
{
    char buffer[256];
    GetCurrentDirectoryA(256, buffer);

    std::string fileName = buffer + imageName;

    std::wstring wideStr = std::wstring(fileName.begin(), fileName.end());

    const wchar_t * finalFile = wideStr.c_str();

    return SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*) finalFile, SPIF_UPDATEINIFILE);
}

std::string pickImage()
{
    size_t size = 0;

    // Get directory size, unforunately no faster way to go about this
    for (const auto& entry : fs::directory_iterator(".\\images"))
    {
        size++;
    }

    // Generate a random 
    srand(time(0));
    int num = rand() % size;

    // Looping until we get to the one we got
    for (const auto & entry : fs::directory_iterator(".\\images")) 
    {
        if (num == 0)
        {
            return entry.path().string();
        }
        num--;

    }
    return "ERROR COULD NOT PICK IMAGE";
}