#include <bits/stdc++.h>
void go() {
  int n, x;
  std::cin >> n;
  char c;
  std::cin >> c;
  std::string s;
  std::cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == c) cnt++;
  }
  if (cnt == n) {
    std::cout << "0\n";
    return;
  }
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    if (s[i] != c) {
      v.push_back(i + 1);
    }
  }
  std::vector<int> a(n + 1, 1);
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
      std::cout << "1\n" << i << "\n";
      return;
    }
  }
  std::cout << "2\n" << n << " " << n - 1 << "\n";
  return;
}
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t = 1;
  std::cin >> t;
  while (t--) {
    go();
  }
  return 0;
}
