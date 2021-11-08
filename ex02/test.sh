make debug
./prog > output.txt
cat 19920104_091532.log | sed -e 's/\[.*\]//g' > expected.txt
gsed -i -e 's/\[.*\]//g' output.txt
diff -y -W 150 output.txt expected.txt
rm -f output.txt expected.txt expected.txt-e output.txt-e
make fclean
