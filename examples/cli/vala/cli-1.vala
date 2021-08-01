static bool append = false;
static bool verbose = false;
static bool op_long = false;
static string filename = null;
static string longextra = null;

// sources is a string array containing all non-option arguments
// https://mail.gnome.org/archives/vala-list/2009-March/msg00090.html
[CCode (array_length = false, array_null_terminated = true)]
static string[] sources;

const OptionEntry[] options = {
    { "append",  'a', 0, OptionArg.NONE,     ref append,
        "Set append mode",     null },
    { "verbose", 'v', 0, OptionArg.NONE,     ref verbose,
        "Set verbose mode",    null },
    { "file",    'f', 0, OptionArg.FILENAME, ref filename,
        "Use F file",         "F"},
    { "long",      0, 0, OptionArg.NONE,     ref op_long,
        "Set long mode",      null },
    { "longextra", 0, 0, OptionArg.STRING,   ref longextra,
        "Set longextra to M", "M" },
    { "",    0, 0, OptionArg.FILENAME_ARRAY, ref sources,
        null,                "FILE..." },
    { null }
};


int main (string[] args) {
    // initialize locale
    Intl.setlocale (LocaleCategory.ALL, "");
    //
    stdout.printf ("command  = %s\n", args[0]);
    stdout.printf ("basename = %s\n", Path.get_basename(args[0]));
    try {
        // parse command line options with GLib
        var opt_context = new OptionContext ("- Cli");
        opt_context.set_help_enabled (true);
        opt_context.add_main_entries (options, null);
        opt_context.parse (ref args);
    } catch (OptionError e) {
        stdout.printf ("%s\n", e.message);
        stdout.printf (
"Run '%s --help' to see a full list of available command line options.\n",
            args[0]);
        return 1;
    }

    // print variables
    if (verbose) {
        stdout.printf ("Cli: verbose ON\n");
    }
    if (append) {
        stdout.printf ("Cli: appemd ON\n");
    }
    if (op_long) {
        stdout.printf ("Cli: long ON\n");
    }
    if (filename != null) {
        stdout.printf ("Cli: file = %s\n", filename);
    }
    if (longextra != null) {
        stdout.printf ("Cli: longextra = %s\n", longextra);
    }
    if (sources != null) {
        int i = 0;
        foreach (string s in sources) {
            stdout.printf("sources[%i]=%s\n", i, s);
            i++;
        }
    }
    return 0;
}


