#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  int n;
  cin >> n;
  int a[n], sum = 0;
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    sum += a[i];
  }
  int s = 0, m = -1;
  while (2 * s <= sum && m < n) s += a[++m];
  s -= a[m];
  if (2 * a[m] >= sum) {
    cout << sum - a[m] << "\n";
    for (int i = 0; i < (n); i++) {
      if (i == m) continue;
      for (int j = 0; j < (a[i]); j++) cout << m + 1 << " " << i + 1 << "\n";
    }
  } else {
    int x = (sum - 2 * s) / 2;
    cout << s + x << "\n";
    int l[200000], r[200000];
    int k = 0;
    for (int i = 0; i < (m); i++) {
      for (int j = 0; j < (a[i]); j++) l[k++] = i;
    }
    k = a[m] - x;
    for (int i = m + 1; i < (n); i++) {
      for (int j = 0; j < (a[i]); j++) r[k++] = i;
    }
    for (int i = s; i < (s + x); i++) l[i] = m;
    for (int i = 0; i < (a[m] - x); i++) r[i] = m;
    for (int i = 0; i < (s + x); i++)
      cout << l[i] + 1 << " " << r[i] + 1 << "\n";
  }
}
