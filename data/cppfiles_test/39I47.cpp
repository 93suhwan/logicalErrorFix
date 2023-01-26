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

void solve(){   
    
    cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;

    if(x1>=w or y1>=h){
        cout<<"0";
        return;
    }

    if(x2+(w-x1)<=W and y2+(h-y1)<=H){
        cout<<min((w-x1),(h-y1));
    }
    else if(x2+(w-x1)<=W){
        cout<<w-x1;
    }
    else if(y2+(h-y1)<=H){
        cout<<h-y1;
    }
    else{
        cout<<-1;
    }
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