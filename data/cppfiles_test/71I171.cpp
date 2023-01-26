#include<bits/stdc++.h>
#define pi 3.141592653589793238
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
#define mt make_tuple

#define printclock cerr<<"Time : "<<1000*(long long double)clock()/(long long double)CLOCKS_PER_SEC<<"ms\n";
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll B) { return (unsigned ll)rng() % B;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long double dist(pair<ll, ll> a, pair<ll,ll> b){
	long double dx = a.ff - b.ff;
	long double dy = a.ss - b.ss;
	return sqrt((dx * dx + dy * dy));
} 
ll bx,by;
long double havefun(int l,int r,auto & good){
	long double ans = 2e9;
	for(int i=l;i<r;i++){
		ans = min(ans, dist(good[l],good[r]) - dist(good[i],good[i+1]) + dist({bx,by}, good[i]) + dist({bx,by}, good[i+1]));
	}
	return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll _T = 1;
    
    //cin >> _T;
    while (_T--) {
        ll n, k;
        cin >> n >> k;
        k--;
        vector<array<ll,3>> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i][0] >> v[i][1];
            v[i][2] = i + 1;
        }
		ll sx, sy;
        

        sx = v[k][0], sy = v[k][1];
        sort(v.begin(), v.end());
        
		
		
        
		map<pair<ll,ll>, ll> slopes;
		for(int i = 1; i < n; i++){
			ll dy, dx;
			dy = v[i][1] - v[0][1];
			dx = v[i][0] - v[0][0];
			ll g = gcd(abs(dx), abs(dy));
			dx /= g, dy /= g;
			slopes[{dy, dx}]++;
		}
		assert((int)slopes.size() != 1);
		ll id = -1;
		if((int)slopes.size() == 2){
			for(int i = 1; i < n; i++){
				ll dy, dx;
				dy = v[i][1] - v[0][1];
				dx = v[i][0] - v[0][0];
				ll g = gcd(abs(dx), abs(dy));
				dx /= g, dy /= g;
				if(slopes[{dy, dx}] == 1){
					bx = v[i][0], by = v[i][1];
					break;
				}
			}
		}
		else{
			bx = v[0][0], by = v[0][1];
		}
		//cout << bx << " $ " << by << "\n";
        vector<pair<ll,ll>> good;
		
        for(int i = 0; i < n; i++){
            if(v[i][0] == bx && v[i][1] == by){
                continue;
            }
			if(v[i][0] == sx && v[i][1] == sy){
				id = (int)good.size() - 1;
			}
            good.pb({v[i][0], v[i][1]});
        }
        if(sx == bx && sy == by){
			long double ans = dist(good[0], {bx, by});
			ans = min(ans, dist(good[n - 2], {bx, by}));
			ans += dist(good[0], good[n - 2]);
            //cout << "$$$\n";
			cout << fixed << setprecision(10) << ans << "\n";
		}
		else{
			//cout << id << "###\n";
			long double ans = 2e9;
			if(id == 0||id == good.size()-1){
				ans = min(ans, havefun(0, good.size()-1, good));
			}
			else{
				long double tmp = dist(good[id], good[0])+dist({bx,by}, good[0])+dist({bx,by}, good[id+1])+dist(good[id+1],good.back());
				ans = min(ans, tmp);
				tmp = dist(good[id], good.back())+dist({bx,by}, good.back())+dist({bx,by}, good[id-1])+dist(good[id-1],good[0]);
				ans = min(ans, tmp);
				ans = min(ans, 2.0*dist(good[0], good[id]) + havefun(id,good.size()-1, good));
				ans = min(ans, 2.0*dist(good[id], good.back()) + havefun(0, id, good));
			}
			cout<<fixed<<setprecision(10)<<ans<<'\n';
			
		}
    }
    return 0;
}