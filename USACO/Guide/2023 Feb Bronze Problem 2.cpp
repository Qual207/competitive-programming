#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<char>> stamp(20, vector<char>(20));
vector<vector<char>> des(20, vector<char>(20));
vector<vector<char>> cur(20, vector<char>(20));
vector<vector<char>> dupl(20, vector<char>(20));
vector<vector<char>> stamp1(20, vector<char>(20));
vector<vector<char>> stamp2(20, vector<char>(20));
vector<vector<char>> stamp3(20, vector<char>(20));
vector<vector<char>> stamp4(20, vector<char>(20));

bool compare(int a, int b, vector<vector<char>> stampInput)
{
    for(int p=a; p<a+k; p++)
    {
        for(int q=b; q<b+k; q++)
        {
            if(des[p][q]=='.' && stampInput[p-a][q-b]=='*')
            {
                return false;
            }
        }
    }
    return true;
}

void rotate()
{
    for(int x=0; x<k; x++)
    {
        for(int y=0; y<k; y++)
        {
            stamp[y][k-1-x] = dupl[x][y];
        }
    }
    for(int x=0; x<k; x++)
    {
        for(int y=0; y<k; y++)
        {
            dupl[x][y] = stamp[x][y];
        }
    }    
}

int main()
{
    int t;
    cin >> t;

    while(t>0)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> des[i][j];
                des[i][j];
                cur[i][j] = '.';
            }
        }
        
        cin >> k;
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++)
            {
                cin >> stamp[i][j];
                dupl[i][j] = stamp[i][j];
            }
        }

        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++) stamp1[i][j] = stamp[i][j];
        }

        rotate();
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++) stamp2[i][j] = stamp[i][j];
        }

        rotate();
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++) stamp3[i][j] = stamp[i][j];
        }

        rotate();
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++) stamp4[i][j] = stamp[i][j];
        }

        for(int i=0; i<=n-k; i++)
        {
            for(int j=0; j<=n-k; j++)
            {
                if(compare(i, j, stamp1))
                {
                    for(int x=i; x<i+k; x++)
                    {
                        for(int y=j; y<j+k; y++)
                        {
                            if(stamp1[x-i][y-j]=='*') cur[x][y]='*';
                        }
                    }
                }
                if(compare(i, j, stamp2))
                {
                    for(int x=i; x<i+k; x++)
                    {
                        for(int y=j; y<j+k; y++)
                        {
                            if(stamp2[x-i][y-j]=='*') cur[x][y]='*';
                        }
                    }
                }
                if(compare(i, j, stamp3))
                {
                    for(int x=i; x<i+k; x++)
                    {
                        for(int y=j; y<j+k; y++)
                        {
                            if(stamp3[x-i][y-j]=='*') cur[x][y]='*';
                        }
                    }
                }
                if(compare(i, j, stamp4))
                {
                    for(int x=i; x<i+k; x++)
                    {
                        for(int y=j; y<j+k; y++)
                        {
                            if(stamp4[x-i][y-j]=='*') cur[x][y]='*';
                        }
                    }
                }
            }
        }

        bool ult = true;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(des[i][j]!=cur[i][j])
                {
                    ult = false;
                    break;
                }
            }
            if(!ult) break;
        }

        if(ult) cout << "YES\n";
        else cout << "NO\n";

        t--;
    }
}
