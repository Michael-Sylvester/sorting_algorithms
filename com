#!/bin/bash

gcc -g -Wall -Wextra -Werror -pedantic  -std=gnu89 main.c $1 print.c -o $2
