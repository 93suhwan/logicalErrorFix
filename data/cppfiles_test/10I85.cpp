
#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
using namespace std;
typedef long long ll;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

ll ans = 0;
const ll M = 1e9 + 7;

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a%M;
        a = a * a%M;
        b >>= 1;
    }
    return res;
}

void solve(ll height, ll width, ll sub_height, ll sub_width){
    if(sub_height <= 0 || sub_width<=0){
        ans += height*width;
        ans %= M-1;
        return;
    }
    
    ll n = height;
    ll m = width;
    ll r = sub_height;
    ll c = sub_width;
    ll tmp = 2*r*c;
    pair<ll,ll> a,b;
    a.first = 1,a.second = 1;
    b.first = height - sub_height + 1, b.second = width - sub_width + 1;
    if(a>b)
        swap(a,b);
    //cout<<"Height is "<<height<<" sub_height is "<<sub_height<<" width is "<<width<<" subwidth is "<<sub_width<<endl;
    //cout<<"n is "<<n<<" m is "<<m<<" a is "<<"("<<a.first<<","<<a.second<<") b is ("<<b.first<<","<<b.second<<")\n";
    //cout<<"r is "<<r<<" c is "<<c<<endl;
    ll sub_height2 = a.first + r - b.first;
    ll sub_width2 = (a.second < b.second)?(a.second+c-b.second):(b.second + c - a.second);
    sub_width2 = max(sub_width2, (ll)0);
    tmp -= sub_height2*sub_width2;
    ans += n*m - tmp;
    ans %= M-1;
    solve(r,c,sub_height2,sub_width2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m,k,r,c;
    cin>>n>>m>>k>>r>>c;
    pair<ll,ll> a,b;
    cin>>a.first>>a.second>>b.first>>b.second;
    if(a>b)
        swap(a,b);
    if(a.first == b.first && a.second == b.second){
        cout<<modpow(k, n*m)<<endl;
        return 0;
    }
    ll tmp = 2*r*c;
    ll sub_height = a.first + r - b.first;
    ll sub_width = (a.second < b.second)?(a.second+c-b.second):(b.second + c - a.second);
    sub_width = max(sub_width, (ll)0);
    tmp -= sub_height*sub_width;
    ans = n*m%(M-1)  + M-1- tmp%(M-1);
    ans %=M-1;
    solve(r,c, sub_height,sub_width);
    //cout<<ans<<endl;
    cout<<modpow(k,ans)<<endl;


    return 0;
}