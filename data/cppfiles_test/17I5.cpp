#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

typedef long long int ll;
typedef pair<int,int> ii;

int b[1000010];
 
struct FenwickTree {
 
	int *ft, size;
 
	FenwickTree(int n) : size(n) {
		ft = new int[n + 1];
		for (int i = 0; i <= n; i++)
			ft[i] = 0;
	}
 
	void update(int idx, int val) {
		while (idx <= size) {
			ft[idx] += val;
			idx += (idx & -idx);
		}
	}
 
	ll query(int idx) {
		ll sum = 0;
		while (idx > 0) {
			sum += ft[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
};
 
ll count(vector<int> &a, int n) {
	FenwickTree ft(n);
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		int idx = int(lower_bound(b, b + n, a[i]) - b);
		a[i] = idx + 1;
		ft.update(idx + 1, 1);
	}
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += ft.query(a[i] - 1);
		ft.update(a[i], -1);
	}
	return cnt;
}

int main() {
	optimizar_io
	int tc, n;
	array<int,200000> p;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> p[i];
		deque<int> dq;
		ordered_set orderSet;
		for (int i = 0; i < n; i++) {
			if (dq.empty()) {
				dq.push_back(p[i]);
			}
			else {
				if (p[i] <= dq.front()) {
					dq.push_front(p[i]);
				}
				else if (p[i] >= dq.back()) {
					dq.push_back(p[i]);
				}
				else {
					int less = orderSet.order_of_key(p[i]);
					int bigger = int(orderSet.size()) - less;
					if (less < bigger)
						dq.push_front(p[i]);
					else
						dq.push_back(p[i]);
				}
			}
			orderSet.insert(p[i]);
		}
		vector<int> a;
		for (int i = 0; i < n; i++) a.push_back(dq[i]);
		// for (auto x : a) cout << x << " ";
		// cout << "\n";
		cout << count(a, n) << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/