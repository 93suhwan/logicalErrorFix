//Challenge: Accepted
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <set>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
void debug() {cout << endl;}
template <class T, class ...U> void debug(T a, U ... b) { cout << a << " "; debug(b...);}
template <class T> void pary(T l, T r) {
	while (l != r) {cout << *l << " ";l++;}
	cout << endl;
}
#define ll long long
#define maxn 100005
#define mod 1000000007
#define pii pair<int, int>
#define ff first
#define ss second
#define io ios_base::sync_with_stdio(0);cin.tie(0);
ll dp[maxn][21];
struct BIT{
	ll bit[maxn];
	void modify(int ind, ll val) {
		for (;ind < maxn;ind += ind & (-ind)) bit[ind] += val;
	}
	ll query(int ind) {
		ll ret = 0;
		for (;ind > 0;ind -= ind & (-ind)) ret += bit[ind];
		return ret;
	}
} b;
vector<int> di[maxn];

int phi[maxn], mark[maxn], from[21];
int main() {
	io
	for (int i = 1;i < maxn;i++) {
		for (int j = i;j < maxn;j += i) di[j].push_back(i);
		phi[i] = 1;
	}	
	for (int i = 2;i < maxn;i++) {
		if (!mark[i]) {
			phi[i] = i - 1;
			for (int j = 2 * i;j < maxn;j += i) {
				int tmp = j / i;
				phi[j] *= i - 1;
				while (tmp % i == 0) {
					phi[j] *= i;	
					tmp /= i;
				}
				mark[j] = 1;
			}
		}	
	}
	for (int i = 1;i < maxn;i++) {
		for (int j:di[i]) b.modify(j, phi[i/j]);
		ll tot = b.query(i);
		dp[i][0] = tot;
		for (int j = 1;j < 21;j++) {
			ll cur = dp[from[j]][j-1] - b.query(from[j]);	
			while (from[j] < i - 1) {
				ll nxt = dp[from[j]+1][j-1] - b.query(from[j]+1);
				if (nxt <= cur) from[j]++, cur = nxt;
				else {
					break;
				}
			}
			dp[i][j] = cur + tot;
			//debug(i, j, from[j]);
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		k--;
		if (k > 20) cout << n << "\n";
		else {
			cout << dp[n][k] << "\n";
		}
	}
}
