# ccwc
Clone of wc in C++

## prerequisites
g++

## installation instructions
bash <(curl -s https://raw.githubusercontent.com/Ryan-Hanover/ccwc/main/install.sh)

## Usage 
Usage: ccwc [option] [filename]

## Options:
  -c    Print the byte count  
  -l    Print the line count  
  -w    Print the word count  
  -m    Print the character count (does not support multi-bytes)  

If no option is provided, the default is equivalent to: -l -w -c  

## Examples:
  ccwc -c test.txt       # Count bytes in test.txt  
  ccwc test.txt          # Count lines, words, and bytes in test.txt  
  cat test.txt | ccwc -l # Count lines from stdin  
