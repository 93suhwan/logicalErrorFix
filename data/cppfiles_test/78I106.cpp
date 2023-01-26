#include <bits/stdc++.h>
using namespace std;
int p[32769];
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
  if (j > 1 && p[j]) {
    set<long long int> res;
    z = j;
    res.insert(1);
    k = 2;
    while (j > 1) {
      while (p[k]) k++;
      while (j % k == 0) {
        j /= k;
        auto it1 = res.begin();
        x = res.size();
        while (x--) {
          z = *it1;
          res.insert(k * z);
          it1++;
        }
      }
      k++;
    }
    for (auto t : res) cout << t << " ";
    cout << "\n";
  } else {
    if (j > 1)
      cout << "1 " << j << "\n";
    else
      cout << 1 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t, n, x, i, j, y, k, m, r, u, v, f, l;
  long long int ans;
  memset(p, 0, sizeof(p));
  for (i = 2; i <= 32768; i++) {
    if (!p[i]) {
      for (j = 2 * i; j <= 32768; j += i) p[j] = 1;
    }
  }
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
