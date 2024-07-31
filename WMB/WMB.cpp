#include <windows.h>
#include <iostream>

bool setWallpaper(std::string imageName);

int main()
{
    std::cout << "HELLO" << std::endl;
    setWallpaper("JHU_Admission.png");
}

bool setWallpaper(std::string imageName)
{
    char buffer[256];
    GetCurrentDirectoryA(256, buffer);

    std::string fileName = buffer + std::string("\\images\\") + imageName;

    std::wstring wideStr = std::wstring(fileName.begin(), fileName.end());

    const wchar_t * finalFile = wideStr.c_str();

    return SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*) finalFile, SPIF_UPDATEINIFILE);
}