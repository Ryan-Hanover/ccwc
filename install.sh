#!/usr/bin/bash

g++ main.cpp ccwc.cpp -o ccwc
mkdir -p ~/.local/bin
mv ccwc ~/.local/bin/
echo "Installed ccwc to ~/.local/bin"