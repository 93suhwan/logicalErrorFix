#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m = 0, x, cnt = 0;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    v.push_back(x);
    if (x == i + 1) cnt++;
  }
  if (cnt == n) {
    cout << 0 << '\n';
    return;
  }
  while (1) {
    bool flag = true;
    if (m % 2 == 0) {
      for (int i = 0; i < n - 1; i += 2) {
        if (v[i] > v[i + 1]) swap(v[i], v[i + 1]);
      }
    } else {
      for (int i = 1; i < n - 1; i += 2) {
        if (v[i] > v[i + 1]) swap(v[i], v[i + 1]);
      }
    }
    ++m;
    for (int i = 0; i < n; ++i) {
      if (v[i] != i + 1) {
        flag = false;
        break;
      }
    }
    if (flag == true) break;
  }
  cout << m << '\n';
}
int main(int argc, char const *argv[]) {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
