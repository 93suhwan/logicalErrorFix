#include <bits/stdc++.h>
using namespace std;

void __dbg() { cout << endl; }
template<typename Arg, typename... Args> void __dbg(Arg A, Args... B) { cout << " " << A; __dbg(B...); }
#define dbg(...)  cout << "(" << #__VA_ARGS__ << "):", __dbg(__VA_ARGS__)

#define endl '\n'
#define vll vector<ll>
#define vprll vector<pair<ll,ll>>
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define precise(x) << fixed << setprecision(x) <<
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define w(chae) int chae; cin>>chae; while(chae--)
#define fr(i, a, b) for(ll i=a; i<b; i++)
#define revFr(x, a, b) for(ll x=a; x>=b; x--)
#define makeAr(n) ll n; cin >> n; ll a[n]; fr(i, 0, n) cin >> a[i]
#define makeAr1(n, x) ll n, x; cin >> n >> x; ll a[n]; fr(i, 0, n) cin >> a[i]
#define makeAr2(n, x, y) ll n, x, y; cin >> n >> x >> y; ll a[n]; fr(i, 0, n) cin >> a[i]

const int inf  = INT_MAX;
const int ninf = INT_MIN;
const int mod  = 1e9 + 7;
const int maxN = 1e6 + 2;

void once()
{
    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
    #endif
}

int main()
{
    fast;
    once();
    
    w(chae)
    {
        makeAr1(n, k);
        sort(a, a+n);
        map<ll,ll> mp;
        if(n==1)
        {
            if(a[0]<=k) cout << 0 << endl;
            else cout << a[0]-k << endl;
            continue;
        }
        ll pre[n] = {0};
        pre[1] = a[1];
        fr(i, 0, n) mp[a[i]]++;
        fr(i, 2, n)
        {
            pre[i] = pre[i-1] + a[i];
        }
        ll ans = INT_MAX;
        ll sum = pre[n-1] + a[0];
        if(sum<=k)
        {
            cout << 0 << endl;
            continue;
        }
        //ll x;
        ll x;

        ll cnt[n] = {0};
        if(a[n-1]!=a[0]) cnt[n-1] = 1;
        revFr(i, n-2, 0)
        {
            if(a[i]!=a[0]) cnt[i] = cnt[i+1]+1;
            else cnt[i] = cnt[i+1];
        }

        fr(i, 1, n)
        {
            ll remNum = n-i;
            sum = pre[i];
            x = floor((double)(k-sum)/(double)remNum);
            //cout << remNum << " " << x << endl;
            ll temp;
            if(x<a[0])
            {
                temp = a[0]-x;
                temp += (n-1-i);
                if(temp<=ans) ans = temp;
            }
            else if(x==a[0])
            {
                temp = n-cnt[i];
                if(temp<=ans) ans = temp;
            }
        }

        if(ans<0) cout << 0 << endl;
        else
        cout << ans << endl;
    }
    
    return 0;
}