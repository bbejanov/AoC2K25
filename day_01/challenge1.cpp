
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Dial
{
    constexpr static int TOTAL_POS = 100;
    int cpos;
    int zero_count;

    Dial() : cpos(TOTAL_POS >> 1), zero_count(0) {}

    void turn(const string & instruction)
    {
        char dir;
        int npos;
        sscanf(instruction.c_str(), "%c%d", &dir, &npos);
        if (dir == 'L')  
            npos = -npos;
        
        cpos = (cpos + npos) % TOTAL_POS;

        if (cpos == 0)
            ++zero_count;
    }
};


int main()
{
    Dial dial;
    ifstream ifile("day1_input.txt");

    string instruction;

    while(!ifile.eof())
    {
        ifile >> instruction;
        dial.turn(instruction);
    }

    cout << dial.zero_count << endl;

    return EXIT_SUCCESS;
}


