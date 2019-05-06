#!/bin/bash

#########################################
#
# Generate class and unittest files to
# implement a new kata
#
######################################
if test $# -lt 1
then
  echo "usage: $0 <kata_name>"
  exit 1
fi

kata=$(echo $1 | tr ' ' '_')

sed 's@TEMPLATE@'"$kata"'@' include/TEMPLATE.h > include/$kata.h
sed 's@TEMPLATE@'"$kata"'@' src/TEMPLATE.cpp > src/$kata.cpp
sed 's@TEMPLATE@'"$kata"'@' test/TEMPLATE_kata.cpp > test/kata_$kata.cpp
sed -i 's@\(### END KATA TO TEST ###\)@${PROJECT_SOURCE_DIR}/test/kata_'"$kata"'.cpp\n\1@' CMakeLists.txt

