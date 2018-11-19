echo "Bonsoir a tous et bienvenue sur le test corewar"


CYCLE=0;
DIF_FLAG=0;
DIFF_FILE="diff_file.txt";
ZAZ="zaz.txt"
OURS="corewar.txt"

while [ $DIF_FLAG = 0 ];
do
	echo "$CYCLE\n"
	./zaz/corewar -d $CYCLE $1 $2 > $ZAZ
	./zaz/corewar -d $CYCLE $1 $2 > $OURS
	diff zaz.txt corewar.txt > $DIFF_FILE
	DIF_FLAG=$(wc -l < $DIFF_FILE);
	((CYCLE++))
done;

echo "CYCLE $CYCLE\n"
diff -y $ZAZ $OURS | colordiff
