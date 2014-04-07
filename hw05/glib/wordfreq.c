/* 	Amanda Lee
 	Software Systems
 	Spring 2014

This program finds the word frequency of Alice in Wonderland (as provided 
by Project Gutenberg. It strips out some basic punctuation and prints the
final hashtable in no particular order. This program is pretty poorly designed
in that most of the logic is in the main function. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>


// This function is called on each key-value pair of the hashtable and 
// prints out the key and value. It returns nothing. 
void printKeyValue( gpointer key, gpointer value, gpointer userData ) {
   char *realKey = (char*)key;
   int realValue = GPOINTER_TO_INT(value);

   printf( "%s => %d\n", realKey, realValue );
   return;
}

int main(int argc, char** argv) {

	//intialize variables
	GHashTable* htable = g_hash_table_new_full(g_str_hash, g_str_equal,free, NULL);
	GIOChannel *gio;
	GError *err = NULL;
	gio = g_io_channel_new_file("toRead.txt", "r", &err);
	GIOStatus ret;
    gchar *ln;
    gsize len;
    char *word, *backup;
    char *sep = "\n\\/:;=-,.#12345678890*!'—\"\?() ";
    int n;
    char *toEnter=NULL;

    do{
    	//open channel, reads file line by line
	    ret = g_io_channel_read_line (gio, &ln, &len, NULL, &err);
	    if (ret == G_IO_STATUS_ERROR)
	            g_error ("Error reading: %s\n", err->message);

	    //read words seperated by punctuation and/or spaces
	    for (word = strtok_r((char *)ln, sep, &backup);
	    	 word; 
	    	 word = strtok_r(NULL, sep, &backup))
	    {
	    	
	    	// Has the word as a key and the frequency as the value
	    	// the frequency is incremented by one each time the word
	    	// appears in the text.
	    	toEnter = strdup(word);
	    	gpointer temp = g_hash_table_lookup(htable, toEnter);
	    	if (temp==NULL){
	    		n = 1;
	    	}
	    	else {
	    		int t = GPOINTER_TO_INT(temp);
	    		n = t+1;
	    	}

	    	g_hash_table_insert (htable, toEnter, GINT_TO_POINTER(n));
	    }
	} while (ret == G_IO_STATUS_NORMAL);

    g_free (ln);

    // print the hash table
	g_hash_table_foreach( htable, printKeyValue, NULL );
    return 0;

}