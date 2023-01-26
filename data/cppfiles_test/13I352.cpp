#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define endl '\n';
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define len(x) int(x.size())
#define get_files ifstream cin("input.txt");ofstream cout("output.txt");

const ll BIG_INF = 2e18;
const ll INF = 2e9;
const int MAXN = 1e5 + 7;
const int alphabet = 26;
const ll mod = 1e9 + 7;//998244353
const int LOG = 30;

mt19937 engine;

int n,m,a,b;

bool check(int i,int j,vector<vector<char> >& ans,char q)
{
    if(i > 0 && ans[i - 1][j] == char(q + 'a')) return false;
    if(i + 1 < n && ans[i + 1][j] == char(q + 'a')) return false;
    if(j > 0 && ans[i][j - 1] == char(q + 'a')) return false;
    if(j + 1 < m && ans[i][j + 1] == char(q + 'a')) return false;
    return true;
}

int main()
{
    fast;
    engine.seed(time(0));
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> a;
        b = (n * m - 2 * a) / 2;
        vector<vector<char> > ans(n,vector<char> (m,'#'));
        if(m == 1 && a > 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if(n % 2 == 0)
        {
            if(a % 2 == 1)
            {
                cout << "NO" << endl;
                continue;
            }
            else
            {
                if(m % 2)
                {
                    for(int i = 0; i < n; i+=2)
                    {
                        for(int q = 0; q < 26; ++q)
                        {
                            int j = m - 1;
                            if(check(i,j,ans,q) && check(i + 1,j,ans,q))
                            {
                                ans[i][j] = char(q + 'a');
                                ans[i + 1][j] = char(q + 'a');
                                break;
                            }
                        }
                    }
                }
                m -= m % 2;
                if(n * m / 2 >= a)
                {
                    cout << "YES" << endl;
                    for(int i = 0; i < n; i+=2)
                    {
                        for(int j = 0; j < m; j+=2)
                        {
                            for(int q = 0; q < 26; ++q)
                            {
                                if(check(i,j,ans,q) && check(i,j + 1,ans,q))
                                {
                                    ans[i][j] = char(q + 'a');
                                    ans[i][j + 1] = char(q + 'a');
                                    break;
                                }
                            }
                            a--;
                            i++;
                            for(int q = 0; q < 26; ++q)
                            {
                                if(check(i,j,ans,q) && check(i,j + 1,ans,q))
                                {
                                    ans[i][j] = char(q + 'a');
                                    ans[i][j + 1] = char(q + 'a');
                                    break;
                                }
                            }
                            a--;
                            i--;
                            if(a == 0) break;
                        }
                        if(a == 0) break;
                    }
                    for(int i = 0; i < n - 1; ++i)
                    {
                        for(int j = 0; j < m; ++j)
                        {
                            if(ans[i][j] == '#' && ans[i + 1][j] == '#')
                            {
                                for(int q = 0; q < 26; ++q)
                                {
                                    if(check(i,j,ans,q) && check(i + 1,j,ans,q))
                                    {
                                        ans[i][j] = char(q + 'a');
                                        ans[i + 1][j] = char(q + 'a');
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    for(int i = 0; i < n; ++i)
                    {
                        for(int j = 0; j < m; ++j)
                        {
                            cout << ans[i][j];
                        }
                        cout << endl;
                    }
                    continue;
                }
                else
                {
                    cout << "NO" << endl;
                    continue;
                }
            }
        }
        else
        {
            if(b % 2 == 1)
            {
                cout << "NO" << endl;
                continue;
            }
            else
            {
                if(n % 2 == 1)
                {
                    for(int j = 0; j < m; j+=2)
                    {
                        for(int q = 0; q < 26; ++q)
                        {
                            int i = n - 1;
                            if(check(i,j,ans,q) && check(i,j + 1,ans,q))
                            {
                                ans[i][j] = char(q + 'a');
                                ans[i][j + 1] = char(q + 'a');
                                break;
                            }
                        }
                    }
                }
                n -= n % 2;
                if(n * m / 2 >= b)
                {
                    cout << "YES" << endl;
                    for(int i = 0; i < n; i+=2)
                    {
                        for(int j = 0; j < m; j+=2)
                        {
                            for(int q = 0; q < 26; ++q)
                            {
                                if(check(i,j,ans,q) && check(i + 1,j,ans,q))
                                {
                                    ans[i][j] = char(q + 'a');
                                    ans[i + 1][j] = char(q + 'a');
                                    break;
                                }
                            }
                            b--;
                            j++;
                            for(int q = 0; q < 26; ++q)
                            {
                                if(check(i,j,ans,q) && check(i + 1,j,ans,q))
                                {
                                    ans[i][j] = char(q + 'a');
                                    ans[i + 1][j] = char(q + 'a');
                                    break;
                                }
                            }
                            b--;
                            j--;
                            if(b == 0) break;
                        }
                        if(b == 0) break;
                    }
                    for(int j = 0; j < m - 1; ++j)
                    {
                        for(int i = 0; i < n; ++i)
                        {
                            if(ans[i][j] == '#' && ans[i][j + 1] == '#')
                            {
                                for(int q = 0; q < 26; ++q)
                                {
                                    if(check(i,j,ans,q) && check(i,j + 1,ans,q))
                                    {
                                        ans[i][j] = char(q + 'a');
                                        ans[i][j + 1] = char(q + 'a');
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    for(int i = 0; i < n; ++i)
                    {
                        for(int j = 0; j < m; ++j)
                        {
                            cout << ans[i][j];
                        }
                        cout << endl;
                    }
                    continue;
                }
                else
                {
                    cout << "NO" << endl;
                    continue;
                }
            }
        }
    }
    return 0;
}




















