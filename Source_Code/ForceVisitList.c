#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

int main(int argc, char *argv[]) {
    if (argc == 1){
        printf("Error: No argument provided\n");
        return -1;
    }

    int index = 0;
    char *listOfURLS[argc - 1];

    while (1) {
        char userInput[100];
        printf("Enter a URL (or type 'exit' to quit): ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = '\0';

        if (strcmp(userInput, "exit") == 0) {
            printf("Exiting the program.\n");
            break;
        }

        listOfURLS[index] = strdup(userInput);
        index++;

        if (strstr(userInput, "http://") != NULL || strstr(userInput, "https://") != NULL) {
            openUrlInBrowser(userInput);
        } else {
            printf("Error: No 'http://' or 'https://' included in provided URL\n");
        }

        sleep(3);
    }

    for (int i = 0; i < index; i++) {
        free(listOfURLS[i]);
    }

    return 0;
}
