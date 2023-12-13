
sudo adduser raniamostafa
sudo addgroup family


if id "$raniamostafa" &>/dev/null; then 
    echo "User RaniaMostafa exists."
fi


if grep -q "^$family" /etc/group; then
    echo "Group Familyy exists."
fi

sudo usermod -a -G family raniamostafa
