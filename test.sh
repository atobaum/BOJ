FILENAME="test.txt"
if [ -n $1 ]; then
	FILENAME=$1
fi
RESULT=`awk 'BEGIN {RS=""} NR==1{print $0}' "$FILENAME" | ./a.out`
ANSWER=`awk 'BEGIN {RS=""} NR==2{print $0}' "$FILENAME"`
echo "result:"
echo "$RESULT"
echo ""
echo "answer:"
echo "$ANSWER"
