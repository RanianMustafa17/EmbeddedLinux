

#!/bin/bash

path="$HOME/.bashrc"

if [ -e "$path" ]; then
    echo 'export HELLO=$HOSTNAME' >> "$path"
    echo 'export LOCAL=$(whoami)' >> "$path"
fi

# Open another terminal
gnome-terminal

