#! /usr/bin/env bash

set -xe

gcc -Wall -Wextra -Werror -o example example.c
./example "$@"