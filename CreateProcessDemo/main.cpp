//
//   CreateProcess (MSDN)
//   https://learn.microsoft.com/en-us/windows/win32/procthread/creating-processes
//   https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessa
//
#include <SDKDDKVer.h>
#include <windows.h>
#include <iostream>

int main(int argc, char* argv[])
{
#ifdef _DEBUG
    const char *target_cmd = "TestConsoleAppD.exe";
#else
    const char *target_cmd = "TestConsoleApp.exe";
#endif

    STARTUPINFO startup_info;
    PROCESS_INFORMATION process_info;
    memset(&startup_info, 0, sizeof(STARTUPINFO));
    startup_info.cb = sizeof(STARTUPINFO);
    memset(&process_info, 0, sizeof(PROCESS_INFORMATION));

    BOOL rv = ::CreateProcess(
        target_cmd,          // LPCTSTR lpApplicationName
        NULL,                // LPTSTR lpCommandLine
        NULL,                // LPSECURITY_ATTRIBUTES lpProcessAttributes
        NULL,                // LPSECURITY_ATTRIBUTES lpThreadAttributes
        FALSE,               // BOOL bInheritHandles
        CREATE_NO_WINDOW,    // DWORD dwCreationFlags
        NULL,                // LPVOID lpEnvironment
        NULL,                // LPCTSTR lpCurrentDirectory
        &startup_info,       // LPSTARTUPINFO lpStartupInfo
        &process_info        // LPPROCESS_INFORMATION lpProcessInformation
        );
    DWORD error = GetLastError();
    error;

    if (rv == FALSE) {
        std::cout << "CreateProcess() failed. error " << error;
        
        return 0;
    }

    std::cout << "CreateProcess() finished..."<< std::endl;
    std::cout << "input exit to kill subprocess and exit"<< std::endl;
    std::string command;
    do {
        std::cin >> command;
        if (command == "exit") {
            TerminateProcess(process_info.hProcess, 1);
        }
    } while (command != "exit");
    // Close process and thread handles. 
    CloseHandle(process_info.hProcess);
    CloseHandle(process_info.hThread);
    return 0;
}