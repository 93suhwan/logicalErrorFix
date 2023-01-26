//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <stack>
#include <queue>
#include <deque>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>-

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

// template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//  order_of_key (k) : Number of items strictly smaller than k .
//  find_by_order(k) : K-th element in a set (counting from zero).
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define show(a) cerr << #a <<" -> "<< a <<" "
#define nl cerr <<"\n"
//#define int ll

const int N = 2e5 + 5;
const int oo = 1e9 + 5;

ll all_pairs(ll sz) {
    return (sz * (sz - 1)) / 2;
}

int n, a[N], b[N], cntA[N], cntB[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        ++cntA[a[i]];
        ++cntB[b[i]];
    }
    ll ans = 0ll;
    for (int i = 1; i <= n; ++i) {
        --cntA[a[i]];
        --cntB[b[i]];
        ans += all_pairs(n - i - cntA[a[i]]);
        ans += all_pairs(n - i - cntB[b[i]]);
        ans -= all_pairs(n - i - cntA[a[i]] - cntB[b[i]]);
    }
    cout << ans <<"\n";
}

 main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	cin >> tests;
	while (tests --) {
		solve();
	}
	return 0;
}
/*
    Just Chalish!
*/
