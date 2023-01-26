#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1) {
    cout << -1;
    return;
  }
  int na = a, nb = b;
  vector<int> v(n);
  for (int i = (0); i < (n); i++) {
    v[i] = i + 1;
  }
  int l = 0, r = n - 1;
  while (l < r) {
    if (b > 0) {
      swap(v[l], v[l + 1]);
      if (l == 0) {
        b--;
      } else {
        a--;
        b--;
      }
      l += 2;
    }
    if (l >= r) break;
    if (a > 0) {
      swap(v[r], v[r - 1]);
      if (r == n - 1) {
        a--;
      } else {
        a--;
        b--;
      }
      r -= 2;
    }
    if (a <= 0 && b <= 0) break;
  }
  if ((a + b) > 0 || (a + b) < -1) {
    cout << -1;
  } else {
    if (a < 0) {
      swap(v[n - 2], v[n - 1]);
    } else if (b < 0) {
      swap(v[0], v[1]);
    }
    for (int i = (0); i < (n); i++) {
      cout << v[i] << " ";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
