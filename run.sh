rm /home/pi/idz2/main
rm /home/pi/idz2/graf.png
cd /home/pi/idz2
gcc main.c -o main
./main
dot -Tpng graf.gv -ograf.png
fim -a graf.png
