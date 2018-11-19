#echo "Bonsoir a tous et bienvenue sur le test corewar"


CYCLE=0;
DIF_FLAG=0;
DIFF_FILE="diff_file.txt";
ZAZ="zaz.txt";
OURS="corewar.txt";
CHAMP_ID=4294967295;
CHAMP_ID2=4294967294;

while [ $DIF_FLAG = 0 ];
do
	echo "$CYCLE\n"
	./zaz/corewar -d $CYCLE $2 $1 > $ZAZ
	./vm/corewar -dump $CYCLE -n $CHAMP_ID $1 -n $CHAMP_ID2 $2 > $OURS
	diff zaz.txt corewar.txt > $DIFF_FILE
	DIF_FLAG=$(wc -l < $DIFF_FILE);
	((CYCLE++))
done;

echo "CYCLE $CYCLE\n"
diff -y $ZAZ $OURS | colordiff
