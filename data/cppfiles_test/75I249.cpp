#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T;
int n;
struct N {
  vector<long long> cave;
  long long val;
  bool operator<(const N &b) const { return val < b.val; }
} node[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> T;
  for (int _ = 1; _ <= T; _++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      node[i].cave.clear();
      int k;
      cin >> k;
      long long val = 0;
      for (int j = 1; j <= k; j++) {
        long long x;
        cin >> x;
        node[i].cave.emplace_back(x + 1 - (j - 1));
        val = max(val, x + 1 - (j - 1));
      }
      node[i].val = val;
    }
    sort(node + 1, node + 1 + n);
    int p = 1;
    long long ans = node[1].val;
    long long pow = ans + node[1].cave.size();
    for (int i = 2; i <= n; i++) {
      if (pow >= node[i].val) {
        pow += node[i].cave.size();
      } else {
        p = i;
        ans = node[i].val;
        pow = ans;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
