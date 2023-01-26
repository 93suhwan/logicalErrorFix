#include <bits/stdc++.h>
#define ll long long int
#define double long double
#define pb push_back
#define endl '\n'
#define er erase
#define sz size
#define in insert
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define INF LONG_LONG_MAX
using namespace std;

int tst, n, t[800050];

void build(int a[], int v, int tl, int tr)
{
    if(tl==tr)
    {
        t[v]=a[tl];
    }
    else
    {
        int tm=(tl+tr)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        t[v]=__gcd(t[2*v], t[2*v+1]);
    }
}

int func(int v, int tl, int tr, int l, int r)
{
    if(l>r) return 0;
    if(tl==l && tr==r) return t[v];
    int tm=(tl+tr)/2;
    return __gcd( func(2*v, tl, tm, l, min(tm, r)), func(2*v+1, tm+1, tr, max(l, tm+1), r) );
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin>>tst;
    while(tst--)
    {
        cin>>n;
        int a[n+10];
        int dif[n+10];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n-1;i++)
            dif[i]=abs(a[i+1]-a[i]);
        build(dif, 1, 0, n-2);
        int ans=1;
        for(int i=0;i<=n-1;i++)
        {
            int x=i, y=n-1;
            while(x<y)
            {
                int mid=(x+y)/2;
                int gcd=func(1, 0, n-2, i, mid);
                if(gcd==1){y=mid;}else{x=mid+1;}
            }
            ans=max(ans, y-i+1);
        }
        cout<<ans<<endl;
    }

    return 0;
}
