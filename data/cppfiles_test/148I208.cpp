#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef priority_queue<ll> prq;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //ook, fbo
#define T ll t;cin>>t;while(t--)
#define vt vector
#define fr(i,a,b) for(ll (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(ll (i)=(a) ; (i) >= (b) ; --(i))
#define trav(e,a) for(auto (e): (a))
#define tra(e,a) for(auto& (e): (a))
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define set_bits __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define lbd(a,x) lower_bound(all((a)),(x)) - (a).begin()
#define ubd(a,x) upper_bound(all((a)),(x)) - (a).begin()
#define sz(x) (ll)(x).size()
#define decimal(x) cout << fixed << setprecision(x)
#define dbg1(x9) cout << #x9 << " = " << x9 << endl
const long long INF=1e18;
const int MAX=1e5;
const ll mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
    T{
        ll w,h;
        cin>>w>>h;
        ll k,mxw=0,mxh=0;
        fr(i,0,1){
            cin>>k;
            ll a[k];
            fr(j,0,k-1){
                cin>>a[j];
            }
            mxw=max(mxw,a[k-1]-a[0]);
        }
        fr(i,0,1){
            cin>>k;
            ll b[k];
            fr(j,0,k-1){
                cin>>b[j];
            }
            mxh=max(mxh,b[k-1]-b[0]);
        }
        if(mxh>mxw){
            cout<<mxh*w*1LL<<endl;
        }
        else{
            cout<<mxw*h*1LL<<endl;
        }
    }
    
    
    return 0;
}
