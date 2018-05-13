#!/bin/sh

dir="../tests"
DIFF=""
tput setaf 4;tput bold;echo Make
make > /dev/null
for t in 1 2 3 4
do
	tput setaf 4;tput bold;echo Test $t
	./emirp < $dir/test$t.txt > ${dir}/output$t.txt
	DIFF=$(diff $dir/output$t.txt ${dir}/expected$t.txt)
	if [ "$DIFF" != "" ]
	then
		tput setaf 1;tput bold;echo FAIL
	else
		tput setaf 2;tput bold;echo PASS
	fi
done
rm $dir/output* > /dev/null
tput setaf 4;tput bold;echo Make Clean
make clean > /dev/null
