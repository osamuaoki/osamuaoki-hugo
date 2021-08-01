#include <boost/program_options.hpp>
#include <iostream>
#include <iterator>
#include <stdlib.h>
using namespace std;

// A helper function to simplify the main part.
template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    return os;
}


int main(int argc, char **argv)
{
    string file;
    string extra;
    try {
        namespace po = boost::program_options;
        po::options_description visible("SYNTAX: cli [OPTION ...] files ...");
        visible.add_options()
            ("append,a", "append option")
            ("help,h", "help message")
            ("verbose,v", "verbose option")
            ("file,f", po::value<string>(&file), "file option")
            ("long", "long option")
            ("longextra", po::value<string>(&extra), "longextra option")
        ;
        po::options_description hidden;
        hidden.add_options()
            ("input-file", po::value< vector<string> >(), "input file")
        ;        
        po::positional_options_description p;
        p.add("input-file", -1);

        po::options_description desc;
        desc.add(visible).add(hidden);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv)
            .options(desc).positional(p).run(), vm);
        po::notify(vm);    

        if (vm.count("help")) {
            cout << visible << "\n";
            return EXIT_FAILURE;
        }
        if (vm.count("append")) {
            cout << "append mode\n";
        }
        if (vm.count("verbose")) {
            cout << "verbose mode\n";
        }
        if (vm.count("file")) {
            cout << "Filename: " 
                 << file << "\n";
        } else {
            cout  << "Filename: (unset)\n";
        }
        if (vm.count("long")) {
            cout << "long mode\n";
        }
        if (vm.count("longextra")) {
            cout << "Longextra: " 
                 << extra << "\n";
        } else {
            cout  << "Longextra: (unset)\n";
        }
        if (vm.count("input-file")) {
            cout << "Input files are: "
                 << vm["input-file"].as< vector<string> >() << "\n";
        }
    }
    catch(exception& e) {
        cerr << "E: " << e.what() << "\n";
        return EXIT_FAILURE;
    }
    catch(...) {
        cerr << "E: unknown type!\n";
    }

    return EXIT_SUCCESS;
}
