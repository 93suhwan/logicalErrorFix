#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 1; i < n; i += 2) {
      s[i] = s[i] == '+' ? '-' : '+';
    }
    int pre[n];
    pre[0] = (s[0] == '+' ? 1 : -1);
    for (int i = 1; i < n; i++) {
      pre[i] = (s[i] == '+' ? 1 : -1) + pre[i - 1];
    }
    int l, r, sum;
    while (q--) {
      cin >> l >> r;
      sum = abs(pre[r - 1] - (l == 1 ? 0 : pre[l - 2]));
      cout << (sum == 0 ? 0 : (sum % 2 == 0 ? 2 : 1)) << '\n';
    }
  }
  return 0;
}
