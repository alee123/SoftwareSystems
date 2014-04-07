# Amanda Lee
# Software Systems
# Spring 2014

# makefile for hello_glib and word_freq
# homework 5

wordfreq: wordfreq.c
	gcc -Wall -o wordfreq wordfreq.c $(shell pkg-config --cflags --libs glib-2.0)

hello_glib: hello_glib.c
	gcc -Wall -o hello_glib hello_glib.c $(shell pkg-config --cflags --libs glib-2.0)