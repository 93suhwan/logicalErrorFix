#include <bits/stdc++.h>
using namespace std;
using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;
void solve() {
  lol x, y;
  cin >> x >> y;
  vector<int> a, b;
  while (x) {
    a.push_back(x & 1);
    x >>= 1;
  }
  while (y) {
    b.push_back(y & 1);
    y >>= 1;
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i + a.size() - 1 < b.size(); ++i) {
    bool same = 1;
    for (int j = i; j <= i + a.size() - 1; ++j)
      if (a[j] != b[j]) {
        same = 0;
      }
    if (!same) continue;
    same = 1;
    for (int j = 0; j < i; ++j) same &= b[j];
    for (int j = i + a.size(); j < b.size(); ++j) same &= b[j];
    if (same) {
      cout << "YES\n";
      return;
    }
  }
  reverse(a.begin(), a.end());
  for (int i = 0; i + a.size() - 1 < b.size(); ++i) {
    bool same = 1;
    for (int j = i; j <= i + a.size() - 1; ++j)
      if (a[j] != b[j]) {
        same = 0;
      }
    if (!same) continue;
    same = 1;
    for (int j = 0; j < i; ++j) same &= b[j];
    for (int j = i + a.size(); j < b.size(); ++j) same &= b[j];
    if (same) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
}
