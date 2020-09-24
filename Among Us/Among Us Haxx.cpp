#include <Windows.h>
#include<TlHelp32.h>
#include <iostream>
#include <tchar.h> // _tcscmp
#include <vector>
#include <stdlib.h>

using namespace std;


DWORD GetModuleBaseAddress(TCHAR* lpszModuleName, DWORD pID) {
    DWORD dwModuleBaseAddress = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID); // make snapshot of all modules within process
    MODULEENTRY32 ModuleEntry32 = { 0 };
    ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

    if (Module32First(hSnapshot, &ModuleEntry32)) //store first Module in ModuleEntry32
    {
        do {
            if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0) // if Found Module matches Module we look for -> done!
            {
                dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
                break;
            }
        } while (Module32Next(hSnapshot, &ModuleEntry32)); // go through Module entries in Snapshot and store in ModuleEntry32


    }
    CloseHandle(hSnapshot);
    return dwModuleBaseAddress;
}

int main()
{
    system("Color 09");
    SetConsoleTitle("Among Us Hack by Nextro - Public Release");
    HWND hwnd_AC = FindWindow(NULL, "Among Us");
    if (hwnd_AC = NULL)
    {
        cout << "Couldn't find process" << endl;
        Sleep(1000);
        exit(0);
    }
    DWORD pID = NULL; // Game process ID
    GetWindowThreadProcessId(hwnd_AC, &pID);
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    char gameName[] = "UnityPlayer.dll";
    DWORD gameBaseAddress = GetModuleBaseAddress(_T(gameName), pID);
    DWORD offsetGameToBaseAddress = 0x0129273C;
    vector<DWORD> pointsOffsets{ 0x5C,0x160,0x7F0,0x5D4,0x14 };
    DWORD baseAddress = NULL;
    // getting the value at gamebase + offset and storing it on baseAddress
    // Speed Hax hack values
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + offsetGameToBaseAddress), &baseAddress, sizeof(baseAddress), 0);
    DWORD pointsAddress = baseAddress; // the address we need
    for (int i = 0; i < pointsOffsets.size() - 1; i++) // we dont want to change the last offset value so we do -1
    {
        ReadProcessMemory(phandle, (LPVOID*)(pointsAddress + pointsOffsets.at(i)), &pointsAddress, sizeof(pointsAddress), 0);
    }
    pointsAddress += pointsOffsets.at(pointsOffsets.size() - 1); // adding the last offset
    // Kill cooldown
    DWORD offsetGameToBaseAddress1 = 0x0129273C;
    vector<DWORD> pointsOffsets1{ 0x5C,0x150,0x6E0,0x6F4,0x20 };
    DWORD baseAddress1 = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + offsetGameToBaseAddress1), &baseAddress1, sizeof(baseAddress1), 0);
    DWORD pointsAddress1 = baseAddress1;
    for (int i = 0; i < pointsOffsets1.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(pointsAddress1 + pointsOffsets1.at(i)), &pointsAddress1, sizeof(pointsAddress1), 0);
    }
    pointsAddress1 += pointsOffsets1.at(pointsOffsets1.size() - 1); // adding the last offset
    //Impostor Vision
    DWORD offsetGameToBaseAddress2 = 0x01295838;
    vector<DWORD> pointsOffsets2{ 0xE8,0x38,0x5D4,0xC0,0x4C4 };
    DWORD baseAddress2 = NULL;

    // Kill cooldown hack values
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + offsetGameToBaseAddress2), &baseAddress2, sizeof(baseAddress2), 0);
    DWORD pointsAddress2 = baseAddress2;
    for (int i = 0; i < pointsOffsets2.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(pointsAddress2 + pointsOffsets2.at(i)), &pointsAddress2, sizeof(pointsAddress2), 0);
    }
    pointsAddress2 += pointsOffsets2.at(pointsOffsets2.size() - 1);
    // kill range
    DWORD offsetGameToBaseAddress3 = 0x012915A0;
    vector<DWORD> pointsOffsets3{ 0x1AC,0x2F4,0x670,0x168,0x428 };
    DWORD baseAddress3 = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + offsetGameToBaseAddress3), &baseAddress3, sizeof(baseAddress3), 0);
    DWORD pointsAddress3 = baseAddress3;
    for (int i = 0; i < pointsOffsets3.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(pointsAddress3 + pointsOffsets3.at(i)), &pointsAddress3, sizeof(pointsAddress3), 0);
    }
    pointsAddress2 += pointsOffsets3.at(pointsOffsets3.size() - 1);
    // teleport
    DWORD offsetGameToBaseAddress4 = 0x012A86E0;
    vector<DWORD> pointsOffsets4{ 0x80,0xD0,0x2C,0x32C };
    DWORD baseAddress4 = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + offsetGameToBaseAddress4), &baseAddress4, sizeof(baseAddress4), 0);
    DWORD pointsAddress4 = baseAddress4;
    for (int i = 0; i < pointsOffsets4.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(pointsAddress4 + pointsOffsets4.at(i)), &pointsAddress4, sizeof(pointsAddress4), 0);
    }
    pointsAddress4 += pointsOffsets4.at(pointsOffsets4.size() - 1);
     // Rainbow Color
    DWORD offsetGameToBaseAddress5 = 0x012C96BC;
    vector<DWORD> pointsOffsets5{ 0x24,0x54,0xC8,0x80 };
    DWORD baseAddress5 = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + offsetGameToBaseAddress5), &baseAddress5, sizeof(baseAddress5), 0);
    DWORD pointsAddress5 = baseAddress5;
    for (int i = 0; i < pointsOffsets5.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(pointsAddress5 + pointsOffsets5.at(i)), &pointsAddress5, sizeof(pointsAddress5), 0);
    }
    pointsAddress5 += pointsOffsets5.at(pointsOffsets5.size() - 1);
    // CrewMate Vision
    DWORD offsetGameToBaseAddress6 = 0x0129273C;
    vector<DWORD> pointsOffsets6{ 0x5C,0x7F0,0x724,0x18 };
    DWORD baseAddress6 = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + offsetGameToBaseAddress6), &baseAddress6, sizeof(baseAddress6), 0);
    DWORD pointsAddress6 = baseAddress6;
    for (int i = 0; i < pointsOffsets6.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(pointsAddress6 + pointsOffsets6.at(i)), &pointsAddress6, sizeof(pointsAddress6), 0);
    }
    pointsAddress6 += pointsOffsets6.at(pointsOffsets6.size() - 1);

    // The Ui Design -- Will Make a menu after im done adding more options --
    cout << "\t\t\t\t\t\Among Us Hacks By Nextro" << endl;
    cout << "\t\t\t\t\t\Press 0 to Exit" << endl;
    cout << "\t\t\t\t\t\Press 1 to Activate Speed Hack" << endl;
    cout << "\t\t\t\t\t\Press 2 to Activate No Kill Cooldown Speed" << endl;
    cout << "\t\t\t\t\t\Press 3 to Activate Impos Vision Hack" << endl;
    cout << "\t\t\t\t\t\Press 4 to Activate Kill Range Hack" << endl;
    cout << "\t\t\t\t\t\Test Press 5 to Teleport To Cafeteria" << endl;
    cout << "\t\t\t\t\t\Press 6 to Activate Rainbow Skin Color" << endl;
    cout << "\t\t\t\t\t\Press 7 to Activate CrewMate Vision Hack" << endl;
    while (true)
    {
        Sleep(50);
        if (GetAsyncKeyState(VK_NUMPAD0)) // exiting
        {
            return 0;
        }
        if (GetAsyncKeyState(VK_NUMPAD1)) // it continues
        {
            cout << "Set Speed Value (1-10) - \n" << endl;
            float hSpeed = NULL;
            hSpeed = 10;
            WriteProcessMemory(phandle, (LPVOID*)(pointsAddress), &hSpeed, 4, 0);
            cout << "\t\t\t\t|| Speed Hack Active |" << "Speed Set To - : " << hSpeed << " || \n\n" << endl;

        }
        if (GetAsyncKeyState(VK_NUMPAD2))
        {
            cout << "Kill Cooldown Hack - " <<" True"<< endl;
            float hKill = NULL;
            hKill = 0;
            WriteProcessMemory(phandle, (LPVOID*)(pointsAddress1), &hKill, 4, 0);
        }
       
        if (GetAsyncKeyState(VK_NUMPAD3))
        {
            cout << "Impos Vision Hack - " << " True" << endl;
            float hImposVis = NULL;
            hImposVis = 100;
            WriteProcessMemory(phandle, (LPVOID*)(pointsAddress2), &hImposVis, 4, 0);
        }
        // it might crash ur game idk sometime it works sometime it doesn't
        if (GetAsyncKeyState(VK_NUMPAD4))
        {
            cout << "Long Range Hack - " << " True" << endl;
            DWORD hKill;
            hKill = 5;
            WriteProcessMemory(phandle, (LPVOID*)(pointsAddress3), &hKill, 4, 0);
            //this all i got
        }
        // teleport hack
        if (GetAsyncKeyState(VK_NUMPAD5))
        {
            double hTp;
            hTp = 1; // update the cords this is just a random value(caffeteria)
            int idk;
            idk = WriteProcessMemory(phandle, (LPVOID*)(pointsAddress4), &hTp, 4, 0);
            cout << "Teleported To Cafeteria" << endl;
        }
        // color hack idk if it works anymore
        if (GetAsyncKeyState(VK_NUMPAD6))
        {
            int col0;
            int col1;
            int col2;
            int col3;
            int col4;
            int col5;
            int col6;
            int col7;
            int col8;
            int col9;
            int col10;
            int col11;
            col0 = 0;
            col1 = 1;
            col2 = 2;
            col3 = 3;
            col4 = 4;
            col5 = 5;
            col6 = 6;
            col7 = 7;
            col8 = 8;
            col9 = 9;
            col10 = 10;
            col11 = 11;
            for (;;)
            {
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col0, 4, 0);
                Sleep(1000);
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col1, 4, 0);
                Sleep(1000);
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col2, 4, 0);
                Sleep(1000);
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col3, 4, 0);
                Sleep(1000);
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col4, 4, 0);
                Sleep(1000);
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col5, 4, 0);
                Sleep(1000);
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col6, 4, 0);
                Sleep(1000);
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col7, 4, 0);
                Sleep(1000);
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col8, 4, 0);
                Sleep(1000);
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col9, 4, 0);
                Sleep(1000);
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col10, 4, 0);
                Sleep(1000);
                WriteProcessMemory(phandle, (LPVOID*)(pointsAddress5), &col11, 4, 0);
                Sleep(1000);
            }
        }
        // crewmate vision
        if (GetAsyncKeyState(VK_NUMPAD7))
        {
            float hcrewmatevis;
            hcrewmatevis = 100;
            cout << "Crewmate Vision Hack - " << " True" << endl;
            WriteProcessMemory(phandle, (LPVOID*)(pointsAddress6), &hcrewmatevis, 4, 0);

        }

    }
}