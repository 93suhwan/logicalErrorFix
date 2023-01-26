#include <bits/stdc++.h>
using namespace std;
bool possible(int x, vector<int>& h) {
  int n = h.size();
  vector<long> can_give(n, 0);
  for (int i = n - 1; i >= 0; --i) {
    long val = h[i];
    if (i + 1 < n) {
      val += can_give[i + 1] / 3;
    }
    if (i + 2 < n) {
      val += 2 * can_give[i + 2] / 3;
    }
    if (val >= x) {
      can_give[i] = (min(val - x, (long)h[i]) / 3) * 3;
    } else
      return false;
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  vector<int> H(n);
  long long sum = 0;
  int lo = 1e9 + 5;
  for (int i = 0; i < n; ++i) {
    cin >> H[i];
    sum += H[i];
    lo = min(lo, H[i]);
  }
  int hi = int(sum / n);
  while (lo < hi) {
    int m = lo + (hi - lo + 1) / 2;
    if (possible(m, H)) {
      lo = m;
    } else {
      hi = m - 1;
    }
  }
  cout << lo << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
