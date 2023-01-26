
#include <bits/stdc++.h>
#define ll long long
long long i,j;
#define IO  ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define en "\n"
#define array(a,n) for(ll i=0;i<n;i++) cin>>a[i];
#define f(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define take int t;cin>>t;while(t--)
using namespace std;
#define MOD 1000000007
typedef pair<int, int> pi;
void solve()
{

    ll  k = -1, ct = 0, sum = 0;
    string s="";
    ll n;
    map<ll, ll> mp;
    vector<pair<ll,ll>> v;
    cin >> n >> k;
    ll a[n];
    f(i, 0, n) cin >> a[i];
    f(i,0,n)
    {
        mp[a[i]]++;
        if(mp[a[i]]<k)
        {
            v.pb({a[i], i});
        }
    }
    ll sz = v.size();
    sz -= v.size() % k;
    sort(v.begin(), v.end(), greater<pair<ll, ll>>());
    ll i = 0, color = 0, ans[n] = {0};
    while(i<v.size() and sz>0)
    {
        ans[v[i].second] = color + 1;
        color++;
        color %= k;
        sz--;
        i++;
    }
    f(i, 0, n) cout << ans[i] << " ";
    cout << en;
}
    int main()
    {

        IO
     //   take
        {
            solve( );
        }
        return 0;
    }