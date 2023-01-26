#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  long long x = 0;
  cout << n - 1 << endl;
  for (long long i = 0; i < n - 1; i++) {
    cout << 1 + x << " " << min(v[i].second + x, n) << " 1" << endl;
    x++;
  }
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
