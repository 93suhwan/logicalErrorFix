#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pi 3.14159265358979323846
#define sqr(a) (a)*(a)
#define v vector
#define ll long long
#define ld long double
#define f first
#define sec second
#define pb push_back
#define pf push_front
#define umap unordered_map
#define mod 1000000007
#define inf 2*1e18

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>uset;

void solve(){
    ll x,y,i;
    cin>>x>>y;
    if (x>y){
        cout<<x+y<<endl;
    }else if (x==y){
        cout<<x<<endl;
    }else{
        cout<<(x+y)/2<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));
    int test;
    cin>>test;
    while (test--){
        solve();
    }
    return 0;
}
