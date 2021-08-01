#p "gcc -Wall -o prime `pkg-config --cflags --libs gtk+-3.0` prime.c"
p "gcc -O9 -Wall -o prime `pkg-config --cflags --libs glib-2.0` prime.c"
p "gcc -E -Wall -o prime.i `pkg-config --cflags --libs glib-2.0` prime.c"
