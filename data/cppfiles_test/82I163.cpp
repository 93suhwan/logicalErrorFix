#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
set<int> se[N];
int n, q, t, l, r;
int sum[N];
string s;
int main() {
  cin >> t;
  while (t--) {
    memset(sum, 0, sizeof sum);
    for (int i = 1; i < N; i++) se[i].clear();
    cin >> n >> q >> s;
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + (s[i - 1] == '+' ? 1 : -1) * (i & 1 == 1 ? 1 : -1);
    }
    for (int i = 2; i <= n; i++) {
      se[sum[i - 1] + sum[i]].insert(i);
    }
    while (q--) {
      cin >> l >> r;
      if (sum[r] - sum[l - 1] == 0)
        cout << 0 << endl;
      else {
        int k = r - l + 1;
        if (k % 2 == 0) {
          cout << "2\n" << l << " ";
          l++;
        } else {
          cout << "1\n";
        }
        cout << *se[sum[r] + sum[l - 1]].lower_bound(l) << endl;
      }
    }
  }
  return 0;
}
