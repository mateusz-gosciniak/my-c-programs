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

int solution(vector<vector<int> > &A)
{
    int numberOfCountries = 0;
    enum ECountries { OPEN, CLOSE };
    vector<vector<int> > B(A);

    for(int i=0; i<A.size();i++)
    {
        int c = 0;
        for(int j=0; j<A[i].size();j++)
        {
            int wall = 0;

            // up
            if(i-1 >= 0)
            {
                if( A[i-1][j] != A[i][j]) /// jest panstwo obok
                {
                    wall++;
                }
                else
                {
                    B[i][j] = OPEN;
                }
            }
            else
            {
                wall++;
            }

            // left
            if(j - 1 >= 0)
            {
                if(A[i][j-1] != A[i][j])
                {
                    wall++;
                }
                else
                {
                    B[i][j] = OPEN;
                }
            }
            else
            {
                wall++;
            }

            // right
            if(j + 1 < A[i].size())
            {
                if(A[i][j+1] != A[i][j])
                {
                    wall++;
                }
                else
                {
                    B[i][j] = OPEN;
                }
            }
            else
            {
                wall++;
            }

            // down
            if(i + 1 < A.size())
            {
                if(A[i+1][j] != A[i][j])
                {
                    wall++;
                    c++;
                }

            }
            else
            {
                wall++;
            }


            if(wall == 4)
            {
                numberOfCountries++;
                A[i][j] = -numberOfCountries;
                B[i][j] = CLOSE;
            }
        }

        if(c == 0)
        {
            numberOfCountries++;
        }
    }


    for(int i=0; i<A.size();i++)
    {
        for(int j=0; j<A[i].size();j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    for(int i=0; i<A.size();i++)
    {
        for(int j=0; j<A[i].size();j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    return numberOfCountries;
}

int main()
{
    vector< vector<int> > A;
    vector<int> row;
    row.push_back(5); row.push_back(4); row.push_back(4); A.push_back(row); row.clear();
    row.push_back(4); row.push_back(3); row.push_back(4); A.push_back(row); row.clear();
    row.push_back(3); row.push_back(2); row.push_back(4); A.push_back(row); row.clear();
    row.push_back(2); row.push_back(2); row.push_back(2); A.push_back(row); row.clear();
    row.push_back(3); row.push_back(3); row.push_back(4); A.push_back(row); row.clear();
    row.push_back(1); row.push_back(4); row.push_back(4); A.push_back(row); row.clear();
    row.push_back(4); row.push_back(1); row.push_back(1); A.push_back(row); row.clear();

    cout << solution(A) << endl;
    return 0;
}
