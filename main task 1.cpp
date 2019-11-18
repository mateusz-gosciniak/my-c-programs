#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class CPhoneNumber {
    string _phoneNumber;
    int _hh;
    int _mm;
    int _ss;
    int _cost;

    public:
        CPhoneNumber(string phoneNumber) : _phoneNumber(phoneNumber), _hh(), _mm(), _ss() {};

        int returnTotalTimeInSec() { return _hh*3600+_mm*60+_ss; }

        int returnTotalCost() { return _cost; }

        void addTime(int hh, int mm, int ss)
        {
            ///time
            _ss += ss;
            while(_ss > 60)
            {
                _ss -= 60;
                _mm++;
            }
            _mm += mm;
            while(_mm > 60)
            {
                _mm -= 60;
                _hh++;
            }
            _hh += hh;

            ///cost
            int cost = 0;
            int seconds = hh*3600+mm*60+ss;
            int minutes = 0;

            if(ss == 0)
                minutes = hh*60+mm;
            else
                minutes = hh*60+mm + 1;

            if (seconds < 300)
                cost = seconds * 3;
            else
                cost = minutes * 150;

            _cost = cost;
        };
};

int solution(string &S)
{
    map<string,CPhoneNumber> Database;


    stringstream workspace(S);
    string line;

    while(!workspace.eof())
    {
        workspace >> line;
        stringstream input(line);

        int hh,mm,ss;
        char junk;
        string phoneNumber;

        input >> hh >> junk >> mm >> junk >> ss >> junk >> phoneNumber;

        CPhoneNumber newPhoneNumber(phoneNumber);
        Database.insert( pair<string,CPhoneNumber> (phoneNumber,newPhoneNumber) );
        Database.find(phoneNumber)->second.addTime(hh,mm,ss);
    }

    int totalCost = 0;
    int freeCost = 0;
    int theLongestCall = 0;
    for (auto& i: Database)
    {
        if (i.second.returnTotalTimeInSec() > theLongestCall)
        {
            theLongestCall = i.second.returnTotalTimeInSec();
            freeCost = i.second.returnTotalCost();
        }

        totalCost += i.second.returnTotalCost();
    }
    totalCost -= freeCost;

    return totalCost;
}

int main()
{
    string S = "00:01:07,400-234-090\n00:05:01,701-080-080\n00:05:00,400-234-090";
    cout << solution(S) << endl;
    return 0;
}
