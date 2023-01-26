#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9;
bool snt(int n) {
  if (n < 2) return 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void solve() {
  int n, cnt = 0;
  cin >> n;
  vector<int> a(n);
  vector<pair<pair<int, int>, int> > p;
  for (auto& x : a) cin >> x;
  for (int i = 0; i < n; i++) {
    int mn = MAX, vt = i;
    for (int j = i; j < n; j++) {
      if (a[j] < mn) {
        mn = a[j];
        vt = j;
      }
    }
    if (vt != i) {
      int index = 0;
      vector<int> tmp(vt - i + 1);
      p.push_back(make_pair(make_pair(i, vt), vt - i));
      tmp[index++] = a[vt];
      for (int k = i; k < vt; k++) {
        tmp[index++] = a[k];
      }
      index = 0;
      for (int k = i; k <= vt; k++) {
        a[k] = tmp[index++];
      }
    }
  }
  cout << p.size() << '\n';
  for (auto x : p) {
    cout << (x.first.first) + 1 << " " << (x.first.second) + 1 << " "
         << x.second << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
