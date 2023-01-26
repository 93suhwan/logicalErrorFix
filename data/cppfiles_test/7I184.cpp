#include <bits/stdc++.h>
using namespace std;
#define i64 long long


int FIXED_RANDOM = rand();
template<typename T> struct SegTree {
	int n; vector<T> t;
	SegTree(int n) : n(n) { t.resize(2*n); }
	T &operator[](int idx) { return t[idx + n]; }
	T merge(T a, T b) { return __gcd(a,b); }
	// initializing Segment Tree

	void update() {
		// update the whole tree -> O(n)

		for (int i = n - 1; !!i; i--)
			t[i] = merge(t[i << 1], t[i << 1 | 1]);
	}
	
	void modify(int a, int b, i64 c = FIXED_RANDOM) {
		// 2 parameters passed -> single   modification -> O(logn)
		// 3 parameters passed -> interval modification -> O(logn)

		if (c == FIXED_RANDOM) {
			for (t[a += n] = b; a >>= 1; )
				t[a] = merge(t[a << 1], t[a << 1 | 1]);
		} else {
			int l = a + n, r = b + n + 1;
			for (; l < r; l >>= 1, r >>= 1) {
				if (l & 1) t[l] = merge(t[l], c), l++;
				if (r & 1) --r, t[r] = merge(c, t[r]);
			}
		}
	}
	
	T getVal(int a = -1, int b = -1) {
		// 1 parameter  passed -> single   access -> O(logn)
		// 2 parameters passed -> interval access -> O(logn)

		if (b == -1) {
			T res = 0;
			for (a += n; !!a; a >>= 1)
				res = merge(res, t[a]);
			return res;
		} else {
			T resL = (* this)[a], resR = ( *this)[b];
			int l = a + n, r = b + n + 1;
			for (; l < r; l >>= 1, r >>= 1) {
				if (l & 1) resL = merge(resL, t[l++]);
				if (r & 1) resR = merge(t[--r], resR);
			} return merge(resL, resR);
		}
	}
};



void KhanhCute(){
	int n; cin >> n;
	vector <int> a(n);
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	if (n == 1) {
		cout << "1\n";
		return;
	}
	SegTree<i64> t(n-1);
	for (int i=0; i<n-1; i++){
		t[i] = abs(a[i+1] - a[i]);
	}
	t.update();
	i64 ans = 0;
	for (i64 i=0; i<n-1; i++){
		i64 l = i, r = n - 2;
		while (l <= r) {
			i64 m = (l + r)/2;
			if (t.getVal(i, m) > 1)
				l = m + 1;
			else
				r = m - 1;
		}	
		ans = max (ans, l - i + 1);		
	}
	cout << ans  << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1; cin >> t;
	for (int i=1; i<=t; i++){
		// cout << "Case #" << i << ": ";
		KhanhCute();
	}
	return 0;
}