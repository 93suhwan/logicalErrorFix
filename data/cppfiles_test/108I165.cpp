#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define mp make_pair

#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG printf("Hi\n")
#define INF 1000000000000000000LL
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define SZ(z) ((int)z.size())
#define sq(x) ((x)*(x))

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)

#define mod 998244353

using namespace __gnu_pbds;
using namespace std ;

typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const double EPS = 1e-9 , PI = acos(-1.0);

#define IN freopen("chainblock_input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
typedef pair<int,int> pii;

#define maxn 200005

pair<int,int> a[maxn], b[maxn];

char s[maxn];

int main()
{
    int tc;
    scanf("%d",&tc);

    while(tc--)
    {
        int n;
        scanf("%d",&n);

        for(int i=1; i<=n; i++) scanf("%d",&a[i].xx);
        for(int i=1; i<=n; i++) scanf("%d",&b[i].xx);

        for(int i=1; i<=n; i++) a[i].yy = b[i].yy = i;

        sort(a+1, a+n+1);
        sort(b+1, b+n+1);

        for(int i=0; i<n; i++) s[i] = '0';
        s[n] = '\0';

        bool fl = false;
        for(int i=1; i<=n; i++)
        {
            if(a[i].yy==b[n].yy) fl = true;
            if(fl) s[a[i].yy-1] = '1';
        }

        fl =false;
        for(int i=1; i<=n; i++)
        {
            if(b[i].yy==a[n].yy) fl = true;
            if(fl) s[b[i].yy-1] = '1';
        }

        printf("%s\n",s);
    }

    return 0;
}
