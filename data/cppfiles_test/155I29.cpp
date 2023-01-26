#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n, i, j, m;
  cin >> n;
  vector<long long> v(n), v1(n);
  string s;
  for (i = 0; i < n; i++) {
    cin >> v[i];
    v1[i] = v[i];
  }
  cin >> s;
  for (i = 1; i < n; i++) {
    if (s[i] > s[i - 1]) {
      v[i] = max(v[i - 1] + 1, v[i]);
    }
  }
  for (i = n - 2; i >= 0; i--) {
    if (s[i + 1] > s[i]) {
      v[i] = max(v[i + 1] + 1, v[i]);
    }
  }
  for (i = n - 2; i >= 0; i--) {
    if (s[i + 1] > s[i]) {
      v1[i] = max(v1[i + 1] + 1, v1[i]);
    }
  }
  for (i = 1; i < n; i++) {
    if (s[i] > s[i - 1]) {
      v1[i] = max(v1[i - 1] + 1, v1[i]);
    }
  }
  long long s1 = 0, s2 = 0;
  for (i = 1; i < n; i++) {
    s1 += abs(v[i] - v[i - 1]);
    s2 += abs(v1[i] - v1[i - 1]);
  }
  if (s1 > s2) {
    for (i = 0; i < n; i++) cout << v1[i] << " ";
  } else {
    for (i = 0; i < n; i++) cout << v[i] << " ";
  }
  cout << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
