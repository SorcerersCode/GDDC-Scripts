#include <stdio.h>

char *url = "https://www.youtube.com/watch?v=z6nngId317g";

void runOnWindws(){
    // Use the windows API to open up the default web browser on the computer to the youtube URL
    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
}

void runOnLinux(){
// Use the system's function to use the default web browser
char command[256];
    snprintf(command, sizeof(command), "xdg-open \"%s\"", url);
    system(command);
}

void runOnUnix(){
// Same command as the Linux system
char command[256];
    snprintf(command, sizeof(command), "xdg-open \"%s\"", url);
    system(command);
}


// Determines the OS by the Macros on compilation and goes from there
int main() {
    #ifdef _WIN32
        printf("Operating System: Windows\n");
	runOnWindows();
    #elif __linux__
        printf("Operating System: Linux\n");
	runOnLinux();
    #elif __unix__
        printf("Operating System: Unix\n");
	runOnUnix();
    #else
        printf("Operating System: Unknown\n");
    #endif

    return 0;
}


// YouTube link: 
// https://www.youtube.com/watch?v=z6nngId317g