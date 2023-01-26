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
#include <string.h>

using namespace std;

#define For(i,i1,i2) for(int i=(int)i1 ; i<=(int)i2 ; i++)
#define Rof(i,i1,i2) for(int i=(int)i1 ; i>=(int)i2 ; i--)
#define int long long
#define NMAX 400005
#define MODU 1000000007
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back


int n,A,B;
int a[NMAX],nho[NMAX];

int solve()
{
    For(i,1,n) nho[i] = a[i] = 0;

    if (abs(A-B)>1) return 0;
    if (A>(n-1)/2 || B>(n-1)/2) return 0;

    int bias = 1;
    if (A<B) bias = -1;
    For(i,2,A+B+2)
    {
        nho[i] = bias*(i-1);
        bias *= -1;
    }
    bias*=-1;
    For(i,A+B+3,n)
            nho[i] = 1*(bias);

    For(i,2,n)
    {
        a[i] = a[i-1] + nho[i];
    }

    int amin = a[1];
    For(i,2,n) amin = min(amin,a[i]);
    For(i,1,n)
    {
        printf("%I64d ",a[i]-amin+1);
    }
    printf("\n");
    return 1;
}

main()
{
    #ifndef ONLINE_JUDGE
    freopen("a.inp","r",stdin);
    #endif // ONLINE_JUDGE

    int t;
    scanf("%I64d",&t);
    For(ncase,1,t)
    {
        scanf("%I64d",&n);
        scanf("%I64d%I64d",&A,&B);
        if (solve()==0)
            printf("-1\n");
    }
}
