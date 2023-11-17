#!/bin/bash

if [[ $EUID -ne 0 ]]; then
    echo "Please run this script as root."
    exit 1
fi

# Disable ls command
chmod 0 /bin/ls

echo "ls command disabled. You can thank me later :)"
