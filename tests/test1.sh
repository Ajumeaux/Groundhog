#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## test
## File description:
## test
##

#test1
echo "Error test n°1"
./groundhog
echo $? > test1
diff test1 ./tests/test1.txt
echo "test 1 OK"
#test2
echo "Error test n°2"
cat ./tests/test2.txt | ./groundhog 1 > test2
echo $? > test2_5
diff test2_5 ./tests/0.txt
diff test2 ./tests/test2_5.txt
echo "test 2 OK"
#test3
echo "Error test n°3"
echo STOP | ./groundhog 3
echo $? > test3
diff test3 ./tests/test1.txt
echo "test 3 OK"
#test4
echo "Error test n°4"
cat ./tests/err.txt | ./groundhog 3 > test4_5
echo $? > test4_10
diff test4_5 ./tests/lm
diff test4_10 ./tests/test1.txt
echo "test 4 OK"
#test5
echo "Error test n°5 + test input n°1"
cat ./tests/test5in.txt | ./groundhog 7 > test5
echo $? > test5_5
diff test5 ./tests/test5.txt
diff test5_5 ./tests/0.txt
echo "test 5 OK"
#test6
echo "Error test n°6 + test input n°2"
cat ./tests/test6in.txt | ./groundhog 3 > test6
echo $? > test6_5
diff test6 ./tests/test6.txt
diff test6_5 ./tests/0.txt
echo "test 6 OK"
