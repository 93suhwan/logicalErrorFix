#pragma GCC target ("sse4")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

#define endl '\n'
#define pb push_back
#define fr first
#define sc second
#define ll long long int
#define ld long double
#define bit(idx) idx&(-idx)
#define bin(x) bitset<32>(x).to_string()
#define all(A) A.begin(), A.end()
#define de(x) cout << #x << " = " << x << endl;

using namespace std;
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using matrix = vector<vector<T>>;
/// find_by_order(x) -> x-th element in the set
/// order_of_key(x)  -> how many elements are smaller than x
/// insert(x)		 -> inserts x into the set

vector<int> new_dp(1024, INT_MAX), old_dp(1024, INT_MAX);

int main(){
	/// ios_base::sync_with_stdio(false); cin.tie(NULL);
	/// freopen("filename.in" , "r", stdin); 
	/// freopen("filename.out", "w", stdout);
	int n; cin >> n;
	old_dp[0] = 0;
	for(int i = 0; i < n; i ++){
		int x; cin >> x;
		new_dp = old_dp;
		for(int j = 0; j <= 1024; j ++){
			int oj = j ^ x;
			if(old_dp[oj] < x){
				new_dp[j] = min(x, new_dp[j]);
			}
		}
		new_dp[x] = min(new_dp[x], x);
		old_dp = new_dp;
	}
	vector<int> ans;
	for(int x = 0; x <= 500; x ++) if(old_dp[x] != INT_MAX) ans.pb(x);
	cout << ans.size() << endl;
	for(auto x : ans) cout << x << " "; cout << endl;
}
/**

*/