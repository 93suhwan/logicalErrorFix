#include <bits/stdc++.h>
using namespace std;
using namespace std;
void debug(vector<long long> v) {
  for (auto t : v)
    cerr << "\033[1m\033[31m" << t << "\n"
         << "\033[0m";
  cerr << "\n";
}
long long n, k;
vector<long long> a;
void take() {
  cin >> n >> k;
  a.clear();
  a.resize(n);
  for (auto &zz : a) cin >> zz;
}
void solve() {
  take();
  if (n == 1) {
    cout << "YES\n";
    return;
  }
  long long start = 0;
  long long end = 1;
  long long l = 0;
  a.push_back(-1 * 1e10);
  for (long long i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) l++;
  }
  l++;
  if (l <= k)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
}
