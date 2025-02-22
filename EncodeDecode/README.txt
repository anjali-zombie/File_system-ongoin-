Name:anjali
roll no: 23111004

encoding:it takes any random no between 0 to 65535 .firstly it calculates no of total bits required by given number in binary form  for encoding scheme,suppose no is 16 then it will take total bits required is 13 and must be encoded in 1101010100001 how?---
scheme:
first log of sixteen is 5 that means 16 requires 5 bits to get represented then same goes for log of 5 is 3 till no of bits required is not equal to 2 ,and delimeters must be added at the end of sequence to indicate sequnce completed and after every log if it is not the end of sequnce delimeter 0 must be added 

to do this in programming i first counted the total no of bits required to store the seqence then applied while loop till total no of bits didn't become zero first stored 1 to indicate after this no. no sequnce exist then write the given no in array using bit manipulation where total_no_bits/8 tells which index in array to write in and total_bits_no%8 tell at which bit to manipulate, using this technique manipluated malloced arry bits till log value of no >= 2. after manipulating bit i sended to decoder to decode the given sequence .

decoder:it take encoded sequence as input and take base case as 2 and read that many bits from encoded sequence convert them in integer and read next that many bits if delimeter of previous element is 0 if delemeter is 1 it will stop loop and return current no as decoded no for given sequence o.w will keep updating decoded value till delimeter is not 1.

    

    
