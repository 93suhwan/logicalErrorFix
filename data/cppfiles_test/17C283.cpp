#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void solve();
int main() {
  long long t = 1;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
long long i, k, j;
bool cmp(vector<int> x, vector<int> y) {
  int count = 0;
  for (k = 0; k < 5; k++) {
    if (x[k] < y[k]) count++;
  }
  return count >= 3;
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int> > a(n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < 5; j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  int gold = 0;
  for (i = 1; 1 < n ? i < n : i > n; 1 < n ? i += 1 : i -= 1) {
    if (cmp(a[i], a[gold])) {
      gold = i;
    }
  }
  for (i = 0; i < n; i++) {
    if (gold == i) continue;
    if (cmp(a[i], a[gold])) {
      gold = n + 1;
      break;
    }
  }
  if (gold == n + 1)
    cout << "-1" << '\n';
  else
    cout << gold + 1 << '\n';
}
