#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    a[i] = make_pair(b, i);
  }
  sort(a.begin(), a.end());
  int cur = 1;
  for (int i = 1; i < n; i++) {
    if (a[i].second - a[i - 1].second != 1) {
      cur += 1;
    }
  }
  cout << (cur <= k ? "YES" : "NO") << "\n";
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int test = 1;
  cin >> test;
  while (test-- > 0) {
    solve();
  }
}
