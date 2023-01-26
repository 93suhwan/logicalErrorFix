#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;


#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
const ll nax = 101;
char ans[nax][nax];
ll dx[] = {1, -1, 0};
ll dy[] = {1, -1, 0};
bool is_valid(ll i, ll j, ll n, ll m) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
char valid_color(ll i, ll j, ll n, ll m) {
	vector<ll> freq(26, 0);
	for(int x = 0; x < 3; x++) {
		for(int y = 0; y < 3; y++) {
			ll l = i + dx[x], r = j + dy[y];
			if(is_valid(l, r, n, m) && ans[l][r] != '*') {
				freq[ans[l][r] - 'a'] = 1;
			}
		}
	}
	for(int i = 0; i < 26; i++) {
		if(!freq[i]) {
			return (char)(i + 'a');
		}
	}
}
void fill_n_even(ll n, ll m, ll k) {
	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			if(ans[i][j] != '*') continue;
			char c = valid_color(i, j, n, m);
			if(k) {
				// horizontal slab
				ans[i][j] = c;
				ans[i][j + 1] = c;
				k--;
			} else {
				// vertical slab
				ans[i][j] = c;
				ans[i + 1][j] = c;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << ans[i][j];
		} cout <<"\n";
	}
}
void fill_n_odd(ll n, ll k, ll m) {
	for(int j = 0; j < m; j += 2) {
		char c = valid_color(0, j, n, m);
		ans[0][j] = c;
		ans[0][j + 1] = c;
		k--;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(ans[i][j] != '*') continue;
			if(k) {
				// two horizontal slabs;
				k--;
				char c = valid_color(i, j, n, m);
				ans[i][j] = c;
				ans[i][j + 1] = c;
				c = valid_color(i + 1, j, n, m);
				ans[i + 1][j] = c;
				ans[i + 1][j + 1] = c;
			} else {
				char c = valid_color(i, j, n, m);
				ans[i][j] = c;
				ans[i + 1][j] = c;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << ans[i][j];
		} cout <<"\n";
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--) {
    	ll n, m, k;
    	cin >> n >> m >> k;
    	ans[n][m];
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			ans[i][j] = '*';
    		}
    	}
    	if(n % 2 == 0 && k % 2 == 0) {
    		if(m % 2 == 0) {
    			cout << "YES\n";
    			fill_n_even(n, m, k);
    		} else {
    			if(2 * k > n * (m - 1)) {
    				cout << "NO\n";
    			} else {
    				cout << "YES\n";
    				fill_n_even(n, m, k);
    			}
    		}
    	} else if(n % 2 == 0 && k % 2 == 1) {
    		cout << "NO\n";
    	} else if(n % 2 == 1) {
    		ll q = (2*k) / m;
    		ll rem = k - m/2;
    		if(rem % 2 == 0 && q > 0) {
    			cout << "YES\n";
    			fill_n_odd(n, k, m);
    		}  else {
    			cout << "NO\n";
    		}
    	} 
    }
}