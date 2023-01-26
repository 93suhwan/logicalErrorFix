#include <bits/stdc++.h>
using namespace std;
const int NMax = 2e5 + 9;
pair<int, int> a[NMax];
int e[NMax];
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return (a.second > b.second);
  return (a.first < b.first);
}
void Solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i - a[i].first + 1;
  }
  sort(a, a + n, cmp);
  int m = 0;
  for (int i = 0; i < n; i++)
    if (a[i].second >= 0) {
      int f = upper_bound(e, e + m, a[i].second) - e;
      if (f == m) m++;
      e[f] = a[i].second;
    }
  cout << m;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solve();
}
