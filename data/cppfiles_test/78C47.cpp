#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int x, long long int y) {
  long long int r = x % y;
  while (r) {
    x = y;
    y = r;
    r = x % y;
  }
  return y;
}
void solve(vector<long long int> &a) {
  long long int i, j, k, x, y, z, n = a.size();
  map<long long int, long long int> m1;
  z = 0;
  vector<long long int> v1;
  j = 0;
  k = 1 << j;
  for (i = 0; i < n; i++) {
    if (a[i] > z) z = a[i];
  }
  while (k <= z) {
    for (i = 0; i < n; i++) {
      if (a[i] & k) m1[k]++;
    }
    j++;
    k = 1 << j;
  }
  for (i = 1; i <= k; i *= 2) {
    if (m1[i]) v1.push_back(m1[i]);
  }
  if (!v1.size()) {
    for (i = 1; i < n + 1; i++) cout << i << " ";
    cout << "\n";
    return;
  }
  if (v1.size() >= 2) {
    j = gcd(v1[0], v1[1]);
    for (i = 2; i < v1.size(); i++) j = gcd(j, v1[i]);
  } else
    j = v1[0];
  vector<long long int> res;
  for (i = 1; i <= sqrt(j); i++) {
    if (j % i == 0) {
      if (i * i == j)
        res.push_back(i);
      else {
        res.push_back(i);
        res.push_back(j / i);
      }
    }
  }
  sort(res.begin(), res.end());
  for (auto t : res) cout << t << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t, n, x, i, j, y, k, m, r, u, v, f, l;
  long long int ans;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long int> a(n);
    for (i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }
    solve(a);
  }
  return 0;
}
