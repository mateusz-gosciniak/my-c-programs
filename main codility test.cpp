#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A)
{
    int length = A.size();

    for(int P = 0; P < length; P++)
    {
        int sumAbeforeP = 0, sumAafterP = 0;

        for (int i = 0; i < P; i++)
            sumAbeforeP += A[i];

        for (int i = P+1; i < length; i++)
            sumAafterP += A[i];

        if (sumAbeforeP == sumAafterP)
            return P;
    }

    return -1;
}

int main()
{
    vector<int> A;
    A.push_back(-1);
    A.push_back(3);
    A.push_back(-4);
    A.push_back(5);
    A.push_back(1);
    A.push_back(-6);
    A.push_back(2);
    A.push_back(1);
    cout << "Solution = " << solution(A) << endl;
    return 0;
}
