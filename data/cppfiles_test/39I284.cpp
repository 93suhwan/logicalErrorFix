#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <tuple>
using namespace std;
 
#define Check(x) cout << "x:" << x << " "
#define Min(x, y, z) min(x, min(z, y))
#define Max(x, y, z) max(x, max(z, y))
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frr(i, a, b) for (int i = a; i >= b; i--)
#define pi (double)acos(-1)
 
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<int> sii;
typedef set<ll> sll;
typedef set<string> sstr;
typedef queue<int> qii;
typedef queue<ll> qll;
typedef priority_queue<int> pqii;
typedef priority_queue<int, vii, greater<int>> rpqii;
typedef priority_queue<ll> pqll;
typedef priority_queue<ll, vll, greater<ll>> rpqll;
typedef deque<int> dqii;
typedef deque<ll> dqll;
typedef stack<int> skii;
typedef stack<ll> skll;
typedef list<int, int> Lii;
typedef list<ll, ll> Lll;
 
const int MAXN = 1e5 + 7;
const int MAXM = 1e9 + 7;
const ll MOD = 1e15 + 7;
const int inf = MAXM;
// ll r[MAXN];
 
ll abso(ll a){
    if(a>0) return a;
    return -1*a;
}

ll W,H,x1,x2,y1,y2,w,h;

bool moveX(ll delx){
    if(x2+delx<=W)
        return true;
    return false;
}

bool moveY(ll dely){
    if(y2+dely<=H)
        return true;
    return false;
}

void solve(){   
    
    cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;

    if(x1>=w or y1>=h){
        cout<<"0.000000";
        return;
    }

    ll delx = w-x1;
    ll dely = h-y1;

    bool canx = moveX(delx);
    bool cany = moveY(dely);

    ll ans;

    if(canx & cany){
        ans = min(delx,dely);
        cout<<ans;
    }
    else if(canx){
        ans = delx;
        cout<<ans;
    }else if(cany){
        ans = dely;
        cout<<ans;
    }else{
        cout<<-1;
        return;
    }
    cout<<".000000";
}
 
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}