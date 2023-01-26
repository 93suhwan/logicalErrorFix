#include <bits/stdc++.h>

#define whole(z) (z).begin (), (z).end ()
#define pw(z) (1LL << (z))
#define sqr(z) (z) * (z)

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using Oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
bool uMin (T &x, T y) {

	return (x > y ? (x = y, 1) : 0);
}

template <typename T>
bool uMax (T &x, T y) {

	return (x < y ? (x = y, 1) : 0);
}

const int MaXn = 1 * 1e5 + 115;

int main () {

#ifdef Locally

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

#else

	ios_base :: sync_with_stdio (0);

#endif

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		int c = 0;

		for (int i = 1; i < 1e3 + 1; i++) 
			if (i * i * i < n + 1)
				c = c + 1;
		
		for (long long i = 1; i < 1e5; i++) 
			if (i * i < n + 1)
				c = c + 1;

		cout << c - 1 << "\n";
	}

	return 0;
}