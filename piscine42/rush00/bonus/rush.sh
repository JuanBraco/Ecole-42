#!/bin/sh

echo "\n\n      Welcome to Rush00 \n\n"
echo " Which rush would you like to run ?\n Pick your Rush\n"
echo "--> Rush 00  :    0\n--> Rush 01  :    1\n--> Rush 02  :    2\n--> Rush 03  :    3\n--> Rush 04  :    4\n"

echo "  ------------- \n "
read RUSH

if [ $RUSH -gt 4 ]
then
	echo "\n This is not an option\n"
	exit
fi

echo "\n Enter a width value\n"
read WIDTH
if [ $WIDTH -lt 0 ]
then
	echo " No negative value allowed\n"
	exit
fi
echo "\n Enter a lenght value\n"
read LENGTH
if [ $LENGTH -lt 0 ]
then
	echo " No negative value allowed\n"
	exit
fi

clear

echo "            Compiling  \n"
sleep 1
echo "     [......................]"
sleep 0.3
echo "     [##....................]"
sleep 0.3
echo "     [#####.................]"
sleep 0.3
echo "     [##########............]"
sleep 0.3
echo "     [###############.......]"
sleep 0.3
echo "     [#####################.]"
sleep 1
echo "     [######################]"
echo "              DONE!\n"
sleep 1

echo "    Program will execute shortly\n"
sleep 1

gcc -Wall -Wextra -Werror ./main/main.c ./main/ft_putchar.c ./rush/rush0$RUSH.c && ./a.out $WIDTH $LENGTH
rm a.out

sleep 10
clear
echo "      Thanks for your time\n"
echo "         See you soon\n"
sleep 2
clear
echo "\n"
