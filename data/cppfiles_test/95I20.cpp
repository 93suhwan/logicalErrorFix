//雪花飄飄北風嘯嘯
//天地一片蒼茫

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=998244353;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

int n,m;
int arr[1000005];
ll grid[1000005];
ll temp[1000005];
int id[1000005];

ii r1[1000005];
ii r2[1000005];

int pos(int i,int j){
	return i*m+j;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) rep(y,0,m) cin>>grid[pos(x,y)];
		
		rep(x,0,n) arr[x]=grid[pos(x,0)];
		
		rep(x,0,n) id[x]=x;
		sort(id,id+n,[](int i,int j){
			return arr[i]<arr[j];
		});
		
		rep(x,0,n) rep(y,0,m) temp[pos(x,y)]=grid[pos(id[x],y)];
		swap(grid,temp);
		
		// rep(x,0,n){
			// rep(y,0,m) cout<<grid[x][y]<<" "; cout<<endl;
		// }
		
		rep(x,0,n){
			rep(y,0,m){
				if (x==0) r1[pos(x,y)]=(ii(grid[pos(x,y)],grid[pos(x,y)]));
				else r1[pos(x,y)]=(ii(min(grid[pos(x,y)],r1[pos(x-1,y)].fi),max(grid[pos(x,y)],r1[pos(x-1,y)].se)));
			}
		}
		rep(x,n,0){
			rep(y,0,m){
				if (x==n-1) r2[pos(x,y)]=(ii(grid[pos(x,y)],grid[pos(x,y)]));
				else r2[pos(x,y)]=(ii(min(grid[pos(x,y)],r2[pos(x+1,y)].fi),max(grid[pos(x,y)],r2[pos(x+1,y)].se)));
			}
		}
		
		bool has=false;
		rep(x,0,n-1){
			int f=0;
			rep(y,0,m-1){
				if (r1[pos(x,y)].se<r2[pos(x+1,y)].fi) f++;
				else break;
			}
			int b=m-1;
			rep(y,m,1){
				if (r2[pos(x+1,y)].se<r1[pos(x,y)].fi) b--;
			}
			
			if (f==b+1 && grid[pos(x,0)]<grid[pos(x+1,0)]){
				has=true;
				
				cout<<"YES"<<endl;
				string s;
				rep(y,0,n){
					if (arr[y]<=grid[pos(x,0)]) s+='B';
					else s+='R';
				}
				cout<<s<<endl;
				cout<<f<<endl;
				
				break;
			}
		}
		
		if (!has){
			cout<<"NO"<<endl;
		}
	}
}
