//nani?
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
#define fs first
#define sc second
#define pb push_back
#define f(i,a,b) for( int i = a; i < b ; i++ )
#define sor(a) sort( a.begin(), a.end() )
#define rsor(a) sort( a.rbegin(), a.rend() )
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
typedef int ll;
typedef double ld;
using namespace std;
using namespace __gnu_pbds;
const ll inf=1e9+7;
const ll INF = 1e18+7;
const ll mod=998244353;
// ac cmtr;
const int MX = 1e6 +5;
 
typedef tree<
pair <ll,ll>,
null_type,
less<pair <ll,ll>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)
template<typename t> void fff(const char* x, t&& val1) { cout<<x<< " : "<<val1<<"\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    fff(xd+1, val2...);
}
//---------------------------
 
ll a[MX];
struct ga{
	ll iz,de,res,val_iz,val_de,mx;
}t[MX];

ga op(ga a, ga b){
	ga ans;
	// res
	ans.res = a.res + b.res;
	if(b.val_iz >= a.val_de) ans.res += a.de*b.iz;
	//iz
	if(a.mx == 1){
		if(b.val_iz >= a.val_de) ans.iz = b.iz + a.iz;
		else ans.iz = a.iz;
	}
	else ans.iz = a.iz;
	//de
	if(b.mx == 1){
		if(b.val_iz >= a.val_de) ans.de = b.de + a.de;
		else ans.de = b.de;
	}
	else ans.de = b.de;
	//val_iz
	ans.val_iz = a.val_iz;
	//val_de
	ans.val_de = b.val_de;
	//mx
	if(a.mx == 1 && b.mx == 1 && b.val_iz >= a.val_de) ans.mx = 1;
	else ans.mx = 0; 
  	return ans;
}

void build(ll v,ll tl, ll tr){
	if(tl == tr){
		t[v] = {1,1,1,a[tl],a[tl],1};
		return;
	}
	ll tm = (tl + tr) >> 1;
	build(2*v,tl,tm);
	build(2*v+1,tm+1,tr);
	t[v] = op(t[2*v],t[2*v+1]);
}
void update(ll v,ll tl,ll tr,ll l,ll r,ll x){
	if(tr < l || tl > r) return;
	if(l <=tl && tr <= r){
		t[v] = {1,1,1,x,x,1};
		return;
	}	
	ll tm = (tl+tr) >> 1;
	update(2*v,tl,tm,l,r,x);
	update(2*v+1,tm+1,tr,l,r,x);
	t[v] = op(t[2*v],t[2*v+1]);
}
vector <ga> cur;
void query(ll v,ll tl,ll tr,ll l,ll r){
	if(tr < l || tl > r) return;
	if(l <=tl && tr <= r){
		cur.pb(t[v]);return;
	}
	ll tm = (tl+tr) >> 1;
	query(2*v,tl,tm,l,r);
	query(2*v+1,tm+1,tr,l,r);	
}

int main(){
    fastio;
    ll n,q; cin >> n >> q;
    f(i,0,n) cin >> a[i];
    build(1,0,n-1);
    while(q--){
    	ll ty,l,r; cin >> ty >> l >> r;
    	if(ty == 1){
    		l--;
    		update(1,0,n-1,l,l,r);
    	}
    	else{
    		l--;r--;
    		cur.clear();
    		query(1,0,n-1,l,r);
    		ga rep = cur[0];
    		for(int i = 1; i< cur.size();i++){
    			rep = op(rep,cur[i]);
    		}
    		cout << rep.res <<  endl;
    	}
    }
    
 
 
 
}