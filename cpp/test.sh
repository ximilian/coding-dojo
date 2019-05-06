#!/bin/bash

cmd_line=""
if [[ $# -gt 0 ]]; then
  cmd_line="--gtest_filter=$*"
fi
./build/bin/ut_coding_dojo_playground $cmd_line
