//     بسم الله الرحمن الرحيم     //
 
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
 
 
#define sa(v) sort(v.begin(), v.end())
#define sd(v) sort(v.begin(), v.end(), greater<>())
#define el << '\n'
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
 
 
ll lcm(ll a, ll b)  {  return (a * b) / __gcd(a, b);  }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const ll infLL = 1e18;
const ll inf = 1e16 + 7;
const ll mod = 1e9 + 7;
const int mx = 1e5 + 123;
 
 
 
int main()
{
 
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int tc = 1;
        cin >> tc;
        while (tc--)
        {
                ll n;
                cin >> n;
                vl a(n);
                vector<pair<int,int>>ans;
                priority_queue<pair<ll,ll>>pq;
                for(int i=0;i<n;i++)
                {
                        cin >> a[i];
                        if(a[i]>0) pq.push({a[i],i+1});
                }
                while(pq.size()>1)
                {
                        ll f1 = pq.top().first;
                        ll f2 = pq.top().second;
                        pq.pop();
                        ll k1 = pq.top().first;
                        ll k2 = pq.top().second;
                        for(int i=0;i<k1;i++)
                        {
                                ans.push_back({f2,k2});
                        }
                        pq.pop();
                        ll remain = f1-k1;
                        if(remain>0) pq.push({remain,f2});
                }
                cout << ans.size() el;
                for(auto i:ans) cout << i.first << " " << i.second el;
        }
        return 0;
}