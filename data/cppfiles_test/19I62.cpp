#include <bits/stdc++.h>
using namespace std;
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define fasty ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define forinc(x,a,b) for(int x=a;x<=b;x++)
#define fordec(x,a,b) for(int x=a;x>=b;x--)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ii pair<int,int>
#define mt make_tuple
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define getbit(x,i) ((x>>(i))&1)
#define batbit(x,i) (x|(1ll<<(i)))
#define tatbit(x,i) (x&~(1<<(i)))
#define gg exit(0);
#define int long long
const int N = 1e3 + 10;
int n;
int a[N];
int f[N*10][2*N];
int maxL;

main()
{
    fasty;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        forinc(i,1,n)
        {
           cin >> a[i];
           maxL = max(maxL , a[i]);
        }
        forinc(i,1,n) for(int l=0 ; l<= 2*maxL ; l++) f[i][l] = 1e15;
        f[0][0]=0;
        forinc(i,0,n-1)
        {
            for(int l=0 ; l<= 2*maxL ; l++)
            {
                if(f[i][l] == 1e15) continue;

                f[i+1][max(0ll , l - a[i+1])] = min( f[i+1][max(0ll , l-a[i+1])] , f[i][l] + a[i+1]);
                if(l + a[i+1] <= 2*maxL) f[i+1][l + a[i+1]] = min(f[i+1][l + a[i+1]]   , max(f[i][l] - a[i+1] , 0ll) );
            }
        }
        int res = 1e18;
        forinc(j,0,2*maxL)
        {
            res = min(res , j + f[n][j]);
        }
        cout << res << "\n";
    }
}
