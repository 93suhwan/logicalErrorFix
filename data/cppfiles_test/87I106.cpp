#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

//Use less<int> for unique elements
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {
	optimizar_io
	int tc, n, m;
	array<int,100000> a;

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) cin >> a[i];
		ordered_set ordSet;
		int ans = 0;
		for (int i = 0; i < m; i++) { 
			int pos = ordSet.order_of_key(a[i]); 
			ans += pos;
			ordSet.insert(a[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/