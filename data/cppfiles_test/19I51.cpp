#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <cstdlib>

using namespace std;

#define For(i,i1,i2) for(int i=(int)i1 ; i<=(int)i2 ; i++)
#define Rof(i,i1,i2) for(int i=(int)i1 ; i>=(int)i2 ; i--)
#define int long long
#define NMAX 2003
#define MODU 1000000007
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

int n,amax;
int a[NMAX],F[5*NMAX][NMAX];

void solve()
{
    For(i,0,n)
    For(j,0,2*amax)
        F[i][j] = LONG_MAX;
    F[0][0] = 0;

    For(i,0,n)
    {
        For(j,0,2*amax)
        if (F[i][j]!=LONG_MAX)
        {
            int r;
            if (F[i][j]+a[i+1] <= 2*amax)
            {
                r = F[i+1][max(0ll,j-a[i+1])];
                r = min(r,F[i][j] + a[i+1]);
                F[i+1][max(0ll,j-a[i+1])] = r;
            }
            if (j+a[i+1] <= 2*amax)
            {
                r = F[i+1][j+a[i+1]];
                r = min(r,max(0ll,F[i][j]-a[i+1]));
                F[i+1][j+a[i+1]] = r;
            }
        }
    }
    int res = LONG_MAX;
    For(j,1,2*amax)
    {
        res = min(res,j+F[n][j]);
    }
    printf("%I64d\n",res);
}


main()
{
    //freopen("a.inp","r",stdin);
    int t;
    //cin>>t;
    scanf("%I64d",&t);
    while(t--)
    {
        //cin>>n;
        amax = 0;
        scanf("%I64d",&n);
        For(i,1,n)
        {
            scanf("%I64d",&a[i]);
            amax = max(amax,a[i]);
        }
        solve();
    }
}
