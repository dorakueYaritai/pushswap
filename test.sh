#! /bin/bash

echo test_no_arg
./push_swap
echo

echo test_one_arg
./push_swap 42
echo 

echo test_okasii_arg
./push_swap two
echo 

echo test_dup
./push_swap 1 2 3 4 5 1
echo 

echo test_intmax
./push_swap 2147483647 1 0
echo 

echo test_intmax+1
./push_swap 2147483648 1 0
echo 

echo test_intmin
./push_swap -2147483648 1 0
echo 

echo test_intmin-1
./push_swap -2147483649 1 0
echo

echo test1
./push_swap 2 3
echo

echo test2
./push_swap 0 1 2
echo

echo test3
./push_swap 1 2 3 4 5 6 7 8 9
echo

echo test4
./push_swap 1 3 5 6 9
echo

echo test_A
ARG="2 1 0"; ./push_swap $ARG | ./checker $ARG
echo

echo test_B
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
echo

echo test_C
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l
ARG="1 5 2 4 3"; ./push_swap $ARG
echo

echo test_D
ARG="3 5 2 1 0"; ./push_swap $ARG | ./checker $ARG
ARG="3 5 2 1 0"; ./push_swap $ARG | wc -l
ARG="3 5 2 1 0"; ./push_swap $ARG
echo


echo test_3arg
./push_swap 0 1 2 | wc -l
./push_swap 0 1 2 | wc -l
./push_swap 0 2 1 | wc -l
./push_swap 1 0 2 | wc -l
./push_swap 1 2 0 | wc -l
./push_swap 2 0 1 | wc -l
./push_swap 2 1 0 | wc -l
echo 3_arg_done
