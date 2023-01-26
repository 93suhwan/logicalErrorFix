#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int>> v(n);
  for (long long int i = 0; i < n; i++) {
    long long int a, ab = 0;
    cin >> a;
    vector<long long int> b(a);
    for (long long int in = 0; in < a; in++) cin >> b[in];
    for (long long int im = 0; im < a; im++) {
      ab = max(ab, b[im] - im);
    }
    v[i] = make_pair(ab, a);
  }
  sort(v.begin(), v.end());
  long long int s = 0, r = 0;
  for (long long int i = 0; i < n; i++) {
    s = max(s, v[i].first - r);
    r += v[i].second;
  }
  cout << s + 1 << endl;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
