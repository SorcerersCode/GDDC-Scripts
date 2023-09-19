#include <stdio.h>
#include <stdlib.h>

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
        printf("Error: Unsupported operating system.\n");
    #endif
}

int main() {
    const char *url = "https://www.youtube.com/watch?v=z6nngId317g";

    printf("Opening URL: %s\n", url);

    openUrlInBrowser(url);

    return 0;
}
