#!/bin/bash

# Compile the program
clang rods.c -o a.out

# Test Case 1 - Functionality Test
echo "Running Test 1:"
echo -e "4\n1, 2\n2, 5\n3, 7\n" | ./a.out
echo ""

# Test Case 2 - One Length Test
echo "Running Test 2:"
echo -e "10\n2, 6\n3, 8\n5, 12\n" | ./a.out
echo ""

# Test Case 3 - Impossible Cuts
echo "Running Test 3:"
echo -e "6\n7, 10\n8, 12\n" | ./a.out
echo ""

# Test Case 4 - One Option Test
echo "Running Test 4:"
echo -e "5\n5, 10\n" | ./a.out
echo ""

# Test Case 5 - Over Limit Test - Fail
echo "Running Test 5:"
echo -e "120\n1, 2\n3, 6\n5, 10\n7, 14\n" | ./a.out
echo ""

# Test Case 6 - Rod Equal to Cut Test
echo "Test 6:"
echo -e "6\n1, 2\n3, 5\n6, 10\n" | ./a.out
echo ""

# Test Case 7 - Same Length Different Value Test - Fail (Weird Output)
echo "Test 7:"
echo -e "8\n2, 3\n2, 6\n4, 7\n" | ./a.out
echo ""

# Test Case 8 - Max Cut Test - Fail (Not sure what's happening)
echo "Test 8:"
echo -e "100\n2, 2\n3, 4\n4, 6\n5, 8\n6, 10\n" | ./a.out
echo ""