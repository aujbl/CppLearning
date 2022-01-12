#!/bin/bash
#Filename: password.sh
echo -e "Enter password: "
stty -echo
read password
stty echo
echo $password
echo Password read.
