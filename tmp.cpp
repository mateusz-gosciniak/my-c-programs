#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void printSecondCharOfHalfSequence(string); /// print every second character from the first half of the sequence

int main()
{
    cout << "Input:" << endl;

    unsigned int t = 0;
    cin >> t;
    if (( t == 0 ) || (t > 100))
        return 0;

    vector<string> words;
    for (unsigned int i = 0; i < t; ++i)
    {
        string word;
        cin >> word;
        words.push_back(word);
    }

    cout << endl;
    cout << "Output:" << endl;

    for_each(words.begin(), words.end(), printSecondCharOfHalfSequence);

    return 0;
}

void printSecondCharOfHalfSequence(string word)
{
    unsigned int halfLength = word.length();

    if(halfLength%2==0)
        halfLength = halfLength/2;
    else
        return;

    string outputWord;
    for (unsigned i = 0; i < halfLength; i+=2)
    {
        outputWord += word[i];
    }

    cout << outputWord << endl;
}
