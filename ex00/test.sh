#!/bin/sh

make debug
./megaphone "shhhhh... I think the students are asleep..." > out

echo "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." > expect

./megaphone Damnit " ! " "Sorry students, I thought this thing was off." >> out

echo "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." >> expect

./megaphone >> out

echo "* LOUD AND UNBEARABLE FEEDBACK NOISE *" >> expect

diff out expect -y
rm -rf out expect megaphone
