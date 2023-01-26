#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  char c;
  cin >> n >> c;
  cin >> s;
  bool f = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] != c) {
      f = 0;
      break;
    }
  }
  if (f) {
    cout << 0 << '\n';
    return;
  }
  if (s[n - 1] == c) {
    cout << 1 << '\n';
    cout << n << '\n';
    return;
  }
  vector<int> pre;
  vector<int> v;
  v.resize(n + 1);
  pre.push_back(0);
  for (int i = 0; i < n; i++) {
    pre.push_back(pre[i] + (s[i] == c));
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] != c) {
      continue;
    }
    bool f1 = 1;
    for (int j = i; j <= n; j += i) {
      if (s[j] != c) {
        f1 = 0;
        break;
      }
    }
    if (f1) {
      cout << 1 << '\n';
      cout << i << '\n';
      return;
    }
  }
  cout << 2 << '\n';
  cout << n << " " << n - 1 << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
