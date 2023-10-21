#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

void openUrlInBrowser(const char *url) {
    #ifdef _WIN32
        // Use the Windows API to open the default web browser on Windows
        if (ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL) <= (HINSTANCE)32) {
            printf("Error: Failed to open the web browser.\n");
        }
    #elif defined(__linux__) || defined(__unix__)
        // Use the system function to open the default web browser on Linux/Unix
        char command[256];
        snprintf(command, sizeof(command), "xdg-open \"%s\"", url);
        if (system(command) != 0) {
            printf("Error: Failed to open the web browser.\n");
        }
    #else
        printf("Error: You're boring :(\n");
    #endif
}

int main(int argc, char* argv[]) {
    
    if(argc == 1){
        printf("Error: No argrument provided\n");
        return -1;
    }

    if(argc > 2){
        printf("Error: No more than 1 argument allowed\n");
        return -1;
    }
    
    char *url = argv[1];

    // Checks to see if the protocol is specified before making the system call
    if(strstr(url, "http://") != NULL){
        openUrlInBrowser(url);
    } else if(strstr(url, "https://") != NULL){
        openUrlInBrowser(url);
    } else {
        printf("Error: No http:// or https:// included in provided url\n");
    }

    return 0;
}