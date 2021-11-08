make debug
./prog | cut -f 2 -d ' ' > output.txt
cat 19920104_091532.log | cut -f 2 -d ' ' > expected.txt
diff -y -W 130 output.txt expected.txt
rm -f output.txt expected.txt
make fclean
