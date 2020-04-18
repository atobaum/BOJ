#!/bin/bash

if [ $# -lt 1 ]; then
	echo "Usage: $0 (problem number)"
fi

test_files=`ls | grep "^$1\.test"`
i=0
for filename in $test_files; do
	i=i+1
	ret=`python3 $1.py < $filename`
	echo "Test $filename:"
	echo "$ret"
done
