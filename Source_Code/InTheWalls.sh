#!/bin/bash

# Detect the operating system
if [[ $(uname -s) == "Linux" ]]; then
    ./open_url_linux
else if [[ $(uname -s) == "Windows" ]]; then 
  
    echo "Unsupported operating system."
fi
