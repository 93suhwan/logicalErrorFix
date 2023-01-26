#include<bits/stdc++.h>
#define int long long
#define fi first
#define sc second
#define fr(i,a,b) for(int i = a; i >= b; i --)
#define fo(i,a,b) for(int i = a; i <= b; i ++)
using namespace std;

const int M = 1e6+6;
int n,b,t;
vector<int> a[M];
pair<int,int> h[M];

bool ck(int o)
{
    fo(i,1,n)
    {
        if(o >= h[i].fi) o += h[i].sc;
        else return false;
    }
    return true;
}

main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> t;
    while(t --)
    {
    cin >> n;
    fo(i,1,n)
    {
        int b,c;
        cin >> b;
        fo(j,1,b) cin >> c, a[i].push_back(c);
    }
    fo(i,1,n)
    {
        int mx = INT_MIN,dl;
        fo(j,0,a[i].size()-1)
            mx = max(mx, a[i][j] - j + 1);
        h[i] = {mx,a[i].size()};
    }
    sort(h+1,h+1+n);
    int l=2,r=1000000001,mid,res;
    bool ok;
    while(l <= r)
    {
        mid = (l+r)/2;
        ok = ck(mid);
        if(ok) res = mid, r = mid-1;
        else l = mid+1;
    }
    cout << res<<"\n";
    fo(i,1,n) a[i].clear();
    }





}
