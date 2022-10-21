#!/bin/sh

set -e

printf ".POSIX:\n# this file is generated, do not modify directly\n\n"

printf "OBJS = %s\n" "$(find . -name "*.c" | cut -c 3- | sed s/\\.c\$/.o/ | xargs)"

printf "\n"

cat template.mk

printf "\n# dependencies\n"

find . -name "*.c" | cut -c 3- | sed s/\\.c\$// | sort | xargs -I {} clang -MM -MG -MQ {}.o {}.c
