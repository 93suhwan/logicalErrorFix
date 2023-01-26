#include <bits/stdc++.h>
using namespace std;
void go() {
  int n, x;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == c) cnt++;
  }
  if (cnt == n) {
    cout << "0\n";
    return;
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (s[i] != c) {
      v.push_back(i + 1);
    }
  }
  vector<int> a(n + 1, 1);
  for (int j = 0; j < v.size(); j++) {
    for (long long int i = 1; i * i <= v[j]; i++) {
      if (v[j] % i == 0) {
        a[i] = 0;
        a[v[j] / i] = 0;
      }
    }
  }
  for (int i = 1; i < n + 1; i++) {
    if (a[i] == 1) {
      cout << "1\n" << i << "\n";
      return;
    }
  }
  cout << "2\n" << n << " " << n - 1 << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    go();
  }
  return 0;
}
