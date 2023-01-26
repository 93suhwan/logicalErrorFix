#include <bits/stdc++.h>
using namespace std;
const int Q = 100;
int n, q, p[100005], r[100005], a[100005];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < n; i++) r[p[i]] = i;
  for (int i = 0; i < n; i++) {
    int first = i;
    for (int j = 0; j < Q; j++) first = p[first];
    a[i] = first;
  }
  while (q--) {
    int t, first, second;
    cin >> t >> first >> second;
    if (t == 2) {
      first--;
      while (second >= Q) {
        second -= Q;
        first = a[first];
      }
      while (second--) first = p[first];
      cout << first + 1 << "\n";
    } else {
      first--;
      second--;
      swap(r[p[first]], r[p[second]]);
      swap(p[first], p[second]);
      int ax = first;
      for (int i = 0; i < Q; i++) ax = p[ax];
      int x2 = first;
      for (int i = 0; i < Q; i++) {
        a[first] = ax;
        first = r[first];
        ax = r[ax];
      }
      swap(first, second);
      ax = first;
      for (int i = 0; i < Q; i++) ax = p[ax];
      x2 = first;
      for (int i = 0; i < Q; i++) {
        a[first] = ax;
        first = r[first];
        ax = r[ax];
      }
    }
  }
}
