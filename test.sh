#!/bin/bash

GREEN="\e[92m"
BLUE="\e[94m"
PURPLE="\e[95m"
WHITE="\e[97m"


echo -e $WHITE 'echo "" | ./checker_linux 1 2 3'
echo -en $GREEN "->"
echo "" | ./checker_linux 1 2 3
echo -en $BLUE "->"
echo "" | valgrind --leak-check=full ./checker 1 2 3
echo -en $PURPLE "->"
echo "" | valgrind --leak-check=full ./checker -v 1 2 3
echo

echo -e $WHITE 'echo "sa" | ./checker_linux 1 2 3'
echo -en $GREEN "->"
echo "sa" | ./checker_linux 1 2 3
echo -en $BLUE "->"
echo "sa" | valgrind --leak-check=full ./checker 1 2 3
echo -en $PURPLE "->"
echo "sa" | valgrind --leak-check=full ./checker -v 1 2 3
echo

echo -e $WHITE 'echo "sa" | ./checker_linux  2 1'
echo -en $GREEN "->"
echo "sa" | ./checker_linux 2 1
echo -en $BLUE "->"
echo "sa" | valgrind --leak-check=full ./checker 2 1
echo -en $PURPLE "->"
echo "sa" | valgrind --leak-check=full ./checker -v 2 1
echo

echo -e $WHITE 'echo "
" | ./checker_linux 1 2 3'
echo -en $GREEN "->"
echo "
" | ./checker_linux 1 2 3
echo -en $BLUE "->"
echo "
" | valgrind --leak-check=full ./checker 1 2 3
echo -en $PURPLE "->"
echo "
" | valgrind --leak-check=full ./checker -v 1 2 3
echo

echo -e $WHITE 'echo "sa
" | ./checker_linux 1 2 3'
echo -en $GREEN "->"
echo "sa
" | ./checker_linux 1 2 3
echo -en $BLUE "->"
echo "sa
" | valgrind --leak-check=full ./checker 1 2 3
echo -en $PURPLE "->"
echo "sa
" | valgrind --leak-check=full ./checker -v 1 2 3
echo
