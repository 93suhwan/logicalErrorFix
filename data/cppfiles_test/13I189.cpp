#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back
#define t top()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define int long long
#define oo 1e18
#define eps 1e-8
#define pow poww

const int N = 2e2 + 5;
int q , n  , m , x , y , z , ans , cur1 , cur2 , k;
char a[N][N];
vector < int > g[1000];


main()
{
    //freopen("test.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n >> m >> k;
        memset(a , 0 , sizeof(a));
        if((n * m) % 2 == 1)
            cout << "NO" << "\n";
        else
        {
            if(n % 2 == 1 && (m / 2) > k)
                cout << "NO" << "\n";
            else
            {
                int nn = n;
                if(n % 2 == 1)
                {
                    FOR(i , 1 , n)
                    {
                        FOR(j , 'a' , 'z')
                            if(i <= 2 || (i > 2 && a[n][i - 2] != j))
                            {
                                a[n][i] = j;
                                break;
                            }
                    }
                    n--;
                    k -= m / 2;
                }
                if((m / 2) * n >= k && (k % 2) == 0)
                {
                    cout << "YES" << "\n";
                    while(n != 0)
                    {
                        int j = 1;
                        while(j <= m)
                        {
                            if(j + 1 <= m && k > 0)
                            {
                                k -= 2;
                                FOR(s , 'a' , 'z')
                                    if(s != a[n + 1][j] && s != a[n][j - 1] && s != a[n + 1][j + 1])
                                    {
                                        a[n][j] = s;
                                        a[n][j + 1] = s;
                                        break;
                                    }
                                FOR(s , 'a' , 'z')
                                    if(s != a[n][j] && s != a[n - 1][j - 1] && s != a[n][j + 1])
                                    {
                                        a[n - 1][j] = s;
                                        a[n - 1][j + 1] = s;
                                        break;
                                    }
                                j += 2;
                            }
                            else
                            {
                                FOR(s , 'a' , 'z')
                                    if(s != a[n + 1][j] && s != a[n][j - 1] && s != a[n - 1][j - 1])
                                    {
                                        a[n][j] = s;
                                        a[n - 1][j] = s;
                                        break;
                                    }
                                j++;
                            }

                        }
                        n -= 2;
                    }
                    FOR(i , 1 , nn)
                    {
                        FOR(j , 1 , m)
                            cout << a[i][j];
                        cout << "\n";
                    }
                }
                else
                    cout << "NO" << "\n";
            }
        }
    }
}
