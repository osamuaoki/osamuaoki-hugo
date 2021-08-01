#include <stdlib.h>
#include <glib.h>
#include <glib/gprintf.h>

int main(int argc, char** argv) {
    GString a;
    if (argc == 2) {
    	a = *g_string_new(argv[1]);
    	g_printf("input  = '%s'\n", a.str);
    	a.str = g_ascii_strup(a.str, a.len);
    	g_printf("OUTPUT = '%s'\n", a.str);
    } else {
    	g_printf("%s put_word_to_be_printed_uppercase\n", argv[0]);
    }
    return EXIT_SUCCESS;
}

