/* WMB.cpp
 * Author: Spencer Ye
 * Last Edited: August 2nd, 2024
 * Version: 0.3.1
 */

#include <windows.h>
#include <iostream>
#include <filesystem>
#include <string>

bool setWallpaper(std::string imageName);

namespace fs = std::filesystem;

int main()
{
    std::cout << "HELLO" << std::endl;
    setWallpaper("JHU_Admission.png");


    size_t size = 0;

    // Looping until all the items of the directory are exhausted
    for (const auto& entry : fs::directory_iterator(".\\images")) {

        // Converting the path to a string
        std::string str = entry.path().string();

        std::cout << str << "DIFF" << std::endl;
        size++;

    }
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