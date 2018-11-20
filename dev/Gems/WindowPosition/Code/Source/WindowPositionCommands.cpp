#include "WindowPositionCommands.h"
#include <Windows.h>
#include <WinUser.h>
#include <CrySystemBus.h>
#include <ISystem.h>
#include <IConsole.h>
#include <AzCore/std/string/conversions.h>

using namespace AZStd;
using namespace WindowPosition;

void WindowPositionCommands::Register()
{
    ISystem* system = nullptr;
    CrySystemRequestBus::BroadcastResult(system,
        &CrySystemRequestBus::Events::GetCrySystem);
    if (system)
    {
        if (IConsole* console = system->GetIConsole())
        {
            console->AddCommand("windowx", WindowX, 0,
                "set X position of the window");
            console->AddCommand("windowy", WindowY, 0,
                "set Y position of the window");
            console->AddCommand("windowxy", WindowXY, 0,
                "set X and Y position of the window");
        }
    }
}

void WindowPositionCommands::Unregister()
{
    ISystem* system = nullptr;
    CrySystemRequestBus::BroadcastResult(system,
        &CrySystemRequestBus::Events::GetCrySystem);
    if (system)
    {
        if (IConsole* console = system->GetIConsole())
        {
            console->RemoveCommand("windowx");
            console->RemoveCommand("windowy");
            console->RemoveCommand("windowxy");
        }
    }
}

namespace
{
    HWND TryToGetWindowHandle()
    {
        HWND handle = GetActiveWindow();
        if (!handle)
        {
            // try console window for dedicated server window
            return GetConsoleWindow();
        }

        return handle;
    }
}

void WindowPositionCommands::WindowX(IConsoleCmdArgs* args)
{
    if (args->GetArgCount() > 1)
    {
        const int x = stoi(AZStd::string(args->GetArg(1)));

        if (HWND handle = TryToGetWindowHandle())
        {
            WINDOWINFO windowInfo;
            windowInfo.cbSize = sizeof(WINDOWINFO);
            if (GetWindowInfo(handle, &windowInfo))
                SetWindowPos(handle, nullptr,
                    x,
                    windowInfo.rcWindow.top,
                    0, 0, SWP_NOOWNERZORDER | SWP_NOSIZE);
        }
    }
}

void WindowPositionCommands::WindowY(IConsoleCmdArgs* args)
{
    if (args->GetArgCount() > 1)
    {
        const int y = stoi(AZStd::string(args->GetArg(1)));

        if (HWND handle = TryToGetWindowHandle())
        {
            WINDOWINFO windowInfo;
            windowInfo.cbSize = sizeof(WINDOWINFO);
            if (GetWindowInfo(handle, &windowInfo))
                SetWindowPos(handle, nullptr,
                    windowInfo.rcWindow.left,
                    y,
                    0, 0, SWP_NOOWNERZORDER | SWP_NOSIZE);
        }
    }
}

void WindowPositionCommands::WindowXY(IConsoleCmdArgs* args)
{
    if (args->GetArgCount() > 2)
    {
        const int x = stoi(AZStd::string(args->GetArg(1)));
        const int y = stoi(AZStd::string(args->GetArg(2)));

        if (HWND handle = TryToGetWindowHandle())
            SetWindowPos(handle, nullptr,
                x, y,
                0, 0, SWP_NOOWNERZORDER | SWP_NOSIZE);
    }
}
