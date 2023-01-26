#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;  
using vpii = vector<pii>;
template <typename key_type, typename value_type, typename comp = less<key_type>>
using rbt_map = tree<key_type, value_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename key_type, typename comp = less<key_type>>
using rbt_set = rbt_map<key_type, null_type, comp>;
#define F(i, a, b) for(int i = (int)a; i <= (int)b; i++)
#define f(i, a, b) for(int i = (int)a; i >= (int)b; i--)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
ld const PI = acos(-1);
ld const E = 1e-7;
int const maxn = 3e5 + 7;

int C_n_2(int n) {
	return n * (n - 1) / 2;
}
ld P;

bool good_prob(int n, int m) {
	int p = C_n_2(m) + m * (n - m);
	int q = C_n_2(n);	
	return ld(p) >= ld(q) * P - E;
}
//#define LOCAL
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif           
	int n;
	cin >> n >> ::P;
	int ans = 0;
	while (!good_prob(n, ans))
		++ans;
	cout << ans << '\n';	
	return 0;
}       		