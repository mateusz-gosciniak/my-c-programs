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

int solution(int n) {
    int d[30];
    int l = 0;

    while (n > 0) {
        d[l] = n % 2;
        n /= 2;
        l++;
    }

    for(int i=l-1;i>=0;i--)
        cout << d[i];
    cout << endl;

    for (int p = 1; p < 1 + l; ++p)
    {
        bool ok = true;
        cout << "ok = true" << endl;
        cout << "p = " << p << endl;

        for (int i = 0; i < l - p; ++i)
        {
            cout << "\t i = " << i << endl;

            cout << "\t d[i] != d[i + p]" << endl;
            cout << "\t " << d[i] << " != " << d[i + p] << endl;

            if (d[i] != d[i + p])
            {
                cout << "\t \t ok = false & break" << endl;
                ok = false;
                break;
            }
        }

        if (ok)
        {
            cout << "\t return p" << endl;
            return (p > l/2) ? -1 : p;
        }
    }
    cout << "return -1" << endl;
    return -1;
}

int main()
{
    cout << solution(955) << endl;
    return 0;
}
