#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize ("01")

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define MOD 1000000007
#define pii pair<int,int>
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> PBDS;
// bool flag = true;

#define MAX 100003
void solve()
{
	string s;
	cin >> s;

	int n = s.length();
	int n1 = 0, n2 = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'a' && s[i + 1] == 'b') {
			n1++;
		} else if (s[i] == 'b' && s[i + 1] == 'a') {
			n2++;
		}
	}
	if (n1 == n2) {
		cout << s << "\n";
	} else {
		if (n1 > n2) {
			n1 = n1 - n2;
			while (n1--) {
				for (int i = 0; i < n - 1; i++) {
					if (s[i] == 'a' && s[i + 1] == 'b') {
						s[i] = 'b';
						break;
					}
				}
			}
			cout << s << "\n";

		} else {
			n2 = n2 - n1;
			while (n2--) {
				for (int i = 0; i < n - 1; i++) {
					if (s[i] == 'b' && s[i + 1] == 'a') {
						s[i] = 'a';
						break;
					}
				}
			}
			cout << s << "\n";
		}
	}

}
signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}