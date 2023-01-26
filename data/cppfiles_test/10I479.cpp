# include <bits/stdc++.h>
 
#define fi first
#define se second
#define ll long long
 
using namespace std;
 
const ll mod = 1e9+7;
const ll N = 2e5+5;
 
int32_t main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen ("socdist1.in", "r", stdin);
	//freopen ("socdist1.out", "w", stdout);
	ll t;
	cin >> t;
	while (t --){
 		ll n, k;
 		cin >> n >> k;
 		ll a[n + 5] = {}, us[n + 5] = {}, ar[n + 5] = {};
 		for (int i = 0; i < n; i ++){
 			cin >> a[i];
 		}
 		for (int i = 0; i < n; i ++){
 			us[a[i]] = us[a[i]] + 1;
 			ar[i] = us[a[i]];
 		}
 		for (int i = 0; i < n; i ++){
 			if (ar[i] > k) ar[i] = 0;
 		}
 		for (int i = 0; i < n; i ++){
 			cout << ar[i] << ' ';
 		}
 		cout << '\n';
 	}
}