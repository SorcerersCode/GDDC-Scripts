#include <windows.h>
#include <stdio.h>

int main() {
    // Get a handle to the mouse device
    HANDLE mouseHandle = CreateFile(L"\\\\.\\Mouse", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    
    if (mouseHandle == INVALID_HANDLE_VALUE) {
        // Handle the error if the device can't be opened
        printf("Failed to open mouse device. Error %d\n", GetLastError());
        return 1;
    }

    // Disable the mouse
    BOOL disabled = DeviceIoControl(mouseHandle, IOCTL_MOUSE_DISABLE, NULL, 0, NULL, 0, NULL, NULL);
    
    if (disabled) {
        printf("Mouse disabled successfully.\n");
    } else {
        printf("Failed to disable the mouse. Error %d\n", GetLastError());
    }

    // Close the handle
    CloseHandle(mouseHandle);
    
    return 0;
}
