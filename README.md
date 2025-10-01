# CS 3503 Assignment 2 - Data Representation and Mapping

 ## Author
 Jacob Gutierrez

 ## Description
 Advanced data representation functions for Owl Tech ’s CPU design team .

 ## What ’s New
 - Direct mapping functions ( oct / hex / bin )
 - Signed number representations
 - Reused test framework from A1

 ## Build Instructions
 ‘‘‘ bash
 gcc -o convert convert . c main . c
 ./ convert
 ‘‘‘
 ## Notes
 I tried to make my code more readable and user friendly by placing large, reusable chunks of code in commented off 'blocks'. It made it really easy to copy and paste large chunks of 
 code from one method to another with minimal if any issues!
 ## Test Results
[Running] cd "c:\Users\Jacob\OneDrive\Desktop\C C++\AdvancedDataRepresentation\" && gcc Assignment2.c -o Assignment2 && "c:\Users\Jacob\OneDrive\Desktop\C C++\AdvancedDataRepresentation\"Assignment2
Test 1: oct_to_bin("725") -> Expected: "111010101", Got: "111010101" [PASS] 1/1
Test 2: oct_to_bin("345") -> Expected: "011100101", Got: "011100101" [PASS] 2/2
Test 3: oct_to_bin("777") -> Expected: "111111111", Got: "111111111" [PASS] 3/3
Test 4: oct_to_bin("0") -> Expected: "000", Got: "000" [PASS] 4/4
Test 5: oct_to_bin("1") -> Expected: "001", Got: "001" [PASS] 5/5
Test 6: oct_to_bin("7") -> Expected: "111", Got: "111" [PASS] 6/6
Test 7: oct_to_bin("10") -> Expected: "001000", Got: "001000" [PASS] 7/7
Test 8: oct_to_bin("100") -> Expected: "001000000", Got: "001000000" [PASS] 8/8
Test 9: oct_to_bin("377") -> Expected: "011111111", Got: "011111111" [PASS] 9/9
Test 10: oct_to_hex("345") -> Expected: "E5", Got: "E5" [PASS] 10/10
Test 11: oct_to_hex("777") -> Expected: "1FF", Got: "1FF" [PASS] 11/11
Test 12: oct_to_hex("100") -> Expected: "40", Got: "40" [PASS] 12/12
Test 13: oct_to_hex("0") -> Expected: "0", Got: "0" [PASS] 13/13
Test 14: oct_to_hex("1") -> Expected: "1", Got: "1" [PASS] 14/14
Test 15: oct_to_hex("7") -> Expected: "7", Got: "7" [PASS] 15/15
Test 16: oct_to_hex("1234") -> Expected: "29C", Got: "29C" [PASS] 16/16
Test 17: oct_to_hex("7654") -> Expected: "FAC", Got: "FAC" [PASS] 17/17
Test 18: hex_to_bin("A3") -> Expected: "10100011", Got: "10100011" [PASS] 18/18
Test 19: hex_to_bin("FF") -> Expected: "11111111", Got: "11111111" [PASS] 19/19
Test 20: hex_to_bin("1A") -> Expected: "00011010", Got: "00011010" [PASS] 20/20
Test 21: hex_to_bin("a3") -> Expected: "10100011", Got: "10100011" [PASS] 21/21
Test 22: hex_to_bin("Ff") -> Expected: "11111111", Got: "11111111" [PASS] 22/22
Test 23: hex_to_bin("aC") -> Expected: "10101100", Got: "10101100" [PASS] 23/23
Test 24: hex_to_bin("0") -> Expected: "0000", Got: "0000" [PASS] 24/24
Test 25: hex_to_bin("1") -> Expected: "0001", Got: "0001" [PASS] 25/25
Test 26: hex_to_bin("F") -> Expected: "1111", Got: "1111" [PASS] 26/26
Test 27: hex_to_bin("CAFE") -> Expected: "1100101011111110", Got: "1100101011111110" [PASS] 27/27
Test 28: hex_to_bin("1234") -> Expected: "0001001000110100", Got: "0001001000110100" [PASS] 28/28
Test 29: to_sign_magnitude("5") -> Expected: "00000000000000000000000000000101", Got: "00000000000000000000000000000101" [PASS] 29/29
Test 30: to_sign_magnitude("1") -> Expected: "00000000000000000000000000000001", Got: "00000000000000000000000000000001" [PASS] 30/30
Test 31: to_sign_magnitude("255") -> Expected: "00000000000000000000000011111111", Got: "00000000000000000000000011111111" [PASS] 31/31
Test 32: to_sign_magnitude("-5") -> Expected: "10000000000000000000000000000101", Got: "10000000000000000000000000000101" [PASS] 32/32
Test 33: to_sign_magnitude("-1") -> Expected: "10000000000000000000000000000001", Got: "10000000000000000000000000000001" [PASS] 33/33
Test 34: to_sign_magnitude("-255") -> Expected: "10000000000000000000000011111111", Got: "10000000000000000000000011111111" [PASS] 34/34
Test 35: to_sign_magnitude("0") -> Expected: "00000000000000000000000000000000", Got: "00000000000000000000000000000000" [PASS] 35/35
Test 36: to_ones_complement("5") -> Expected: "00000000000000000000000000000101", Got: "00000000000000000000000000000101" [PASS] 36/36
Test 37: to_ones_complement("1") -> Expected: "00000000000000000000000000000001", Got: "00000000000000000000000000000001" [PASS] 37/37
Test 38: to_ones_complement("255") -> Expected: "00000000000000000000000011111111", Got: "00000000000000000000000011111111" [PASS] 38/38
Test 39: to_ones_complement("-5") -> Expected: "11111111111111111111111111111010", Got: "11111111111111111111111111111010" [PASS] 39/39
Test 40: to_ones_complement("-1") -> Expected: "11111111111111111111111111111110", Got: "11111111111111111111111111111110" [PASS] 40/40
Test 41: to_ones_complement("-255") -> Expected: "11111111111111111111111100000000", Got: "11111111111111111111111100000000" [PASS] 41/41
Test 42: to_ones_complement("0") -> Expected: "00000000000000000000000000000000", Got: "00000000000000000000000000000000" [PASS] 42/42
Test 43: to_twos_complement("5") -> Expected: "00000000000000000000000000000101", Got: "00000000000000000000000000000101" [PASS] 43/43
Test 44: to_twos_complement("1") -> Expected: "00000000000000000000000000000001", Got: "00000000000000000000000000000001" [PASS] 44/44
Test 45: to_twos_complement("255") -> Expected: "00000000000000000000000011111111", Got: "00000000000000000000000011111111" [PASS] 45/45
Test 46: to_twos_complement("-5") -> Expected: "11111111111111111111111111111011", Got: "11111111111111111111111111111011" [PASS] 46/46
Test 47: to_twos_complement("-1") -> Expected: "11111111111111111111111111111111", Got: "11111111111111111111111111111111" [PASS] 47/47
Test 48: to_twos_complement("-255") -> Expected: "11111111111111111111111100000001", Got: "11111111111111111111111100000001" [PASS] 48/48

[Done] exited with code=0 in 0.487 seconds
Test 49: to_twos_complement("0") -> Expected: "00000000000000000000000000000000", Got: "00000000000000000000000000000000" [PASS] 49/49
Test 50: to_twos_complement("2147483647") -> Expected: "01111111111111111111111111111111", Got: "01111111111111111111111111111111" [PASS] 50/50
Test 51: to_twos_complement("-2147483648") -> Expected: "10000000000000000000000000000000", Got: "10000000000000000000000000000000" [PASS] 51/51
