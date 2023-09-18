#include <stdio.h>

void runOnWindws(){
// Find different web browsers in system32 file
}

void runOnLinux(){
// Find different web browsers in file structure
}


void runOnUnix(){
// Find different web browsers in file structure
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
        printf("Operating System: Unix-like\n");
	runOnUnix();
    #else
        printf("Operating System: Unknown\n");
    #endif

    return 0;
}


// YouTube link: 
// https://www.youtube.com/watch?v=z6nngId317g


