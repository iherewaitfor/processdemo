#include <stdio.h>
#include <time.h>
#include <iostream>
#include <Windows.h>
int main(int argc, char* argv[])
{    
    time_t t;
    struct tm d;
    char buf[128];
    FILE *fp = NULL;

    time(&t);
    localtime_s(&d, &t);
    strftime(buf, 123, "%Y/%m/%d-%H:%M:%S", &d);

    printf("TestConsoleApp.exe : touch _hoge.txt %s\n", buf);
    
    fopen_s(&fp, "_hoge.txt", "w");
    if (fp) {
        fprintf(fp, "TestConsoleApp.exe : touch _hoge.txt %s\n", buf);
        fclose(fp);
    }
    std::cout << "input:";
    Sleep(120000);
    return 0;
}