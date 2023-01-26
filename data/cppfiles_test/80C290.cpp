#include <bits/stdc++.h>
using namespace std;
const int c = 100005;
long long n;
vector<long long> a;
bool read() {
  if (!(cin >> n)) return false;
  a.resize(n + 1);
  for (long long i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  return true;
}
void solve() {
  long long k;
  cin >> k;
  string t;
  cin >> t;
  long long kl = -1, kr = -1;
  for (long long i = 0; i < k / 2; ++i) {
    if (t[i] == '0') {
      kl = i;
      break;
    }
  }
  if (kl != -1) {
    cout << kl + 1 << " " << k << " " << kl + 2 << " " << k << '\n';
    return;
  }
  for (long long i = k / 2; i < k; ++i) {
    if (t[i] == '0') {
      kr = i;
      break;
    }
  }
  if (kr != -1) {
    cout << 1 << " " << kr + 1 << " " << 1 << " " << kr << '\n';
    return;
  }
  cout << 1 << " " << k - 1 << " " << 2 << " " << k << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
