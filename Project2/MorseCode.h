#pragma once
#include <string>
using namespace std;

class MorseCode {
private:
    string letter;
    string code;

public:

    MorseCode(string l,string c) {
        letter = l;
        code = c;
    }

    string GetLetter() {
        return letter;
    }

    const string GetCode()  const {
        return code;
    }

    friend ostream& operator<< (ostream& output, const MorseCode& fract) {
        output << fract.code;
        return output;
    }

};

