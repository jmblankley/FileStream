#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{

    string fname;
    cout << "What is the name of your input file? aaa";
    cin >> fname;

    ifstream reader(fname);
    if (!reader)
    {
        // cerr prints out where you want to print out errors
        cerr << "Could not open \"" << fname << '"' << endl;
        // ends the current function
        return 1;
    }

    int nextVal;
    reader >> nextVal;

    if (!reader)
    {
        cerr << "File had no data in it!!!" << endl;
        return 2;
    }
    int sum = 0;

    while (reader) // read did work
    {
        // cout << "File had " << nextVal << " in it!" << endl;

        sum += nextVal;
        reader >> nextVal;
    }
    cout << "Enter the name of an output file: ";
    cin >> fname;

    ofstream ofs(fname);

    ofs << "The sum of all those values is: " << sum << endl;

    ofs.close();
    reader.close();
    return 0;
}