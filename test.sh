TEST=`cat "$1.in" | ./a.out`

echo $TEST | diff "$1.out" -
