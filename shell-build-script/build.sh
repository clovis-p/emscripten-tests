#!/bin/bash
# Clovis Perreault
# 18 sept 2023

# Set working directory to project root
# Make sure emsdk/ is in your home folder

##################################################

# For some reason the emcc command only works for me when I just
# ran the script that sets the environment variables. Since I
# can't be bothered to find out why, I just run it every time.

cd ~/emsdk

source ./emsdk_env.sh

cd -

emcc -o Public/index.html -s USE_SDL=2 Src/main.c -v

# I've had problems running emscipten projects on their own, so I
# setup a local server to run them on.

DIR_NAME=$(date '+%Y-%m-%d_%H-%M-%S')
sudo mkdir "/var/www/html/$DIR_NAME"
sudo cp Public/* "/var/www/html/$DIR_NAME"

firefox "http://localhost/$DIR_NAME"