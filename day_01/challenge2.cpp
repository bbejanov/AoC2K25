
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

    static int decode_instruction(const string & instruction)
    {
        char dir;
        int npos;
        sscanf(instruction.c_str(), "%c%d", &dir, &npos);
        if (dir == 'L')  
            npos = -npos;
        return npos;
    }

    void turn(const string & instruction)
    {
        int npos = Dial::decode_instruction(instruction);

        if (cpos > 0 && npos <= -cpos)
            ++zero_count;
        if (cpos < 0 && npos >= -cpos)
            ++zero_count;
        cpos += npos;
        zero_count += abs(cpos) / TOTAL_POS;
        cpos = cpos % TOTAL_POS;
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


