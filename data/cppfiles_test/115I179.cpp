#include <bits/stdc++.h>
using namespace std;
int binMultiply(int a, int b) {
  int ans = 0;
  while (b) {
    if (b & 1) {
      ans = (ans + a) % 1000000007;
    }
    a = (a + a) % 1000000007;
    b >>= 1;
  }
  return ans;
}
int binExIter(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = binMultiply(ans, a);
    }
    a = binMultiply(a, a);
    b >>= 1;
  }
  return ans;
}
void solve() {
  int n, h;
  cin >> n >> h;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int lo = 1;
  int hi = h;
  int k = h;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    int attack = 0;
    for (int i = 0; i < n; i++) {
      int current = mid;
      if (i < n - 1) {
        int d = v[i + 1] - v[i];
        if (d < mid) {
          current = d;
        }
      }
      attack += current;
    }
    if (attack >= h) {
      k = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << k << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
