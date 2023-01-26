#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
void solve() {
  long long int n, d, a;
  cin >> n >> d;
  vector<long long int> v;
  long long int on = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a;
    if (a) {
      on++;
    }
    v.push_back(a);
  }
  if (!on) {
    cout << "0"
         << "\n";
    return;
  }
  long long int mx = 0, cycle = 0;
  for (long long int i = 0; i < n; i++) {
    if (v[i] != 1) {
      continue;
    }
    long long int ln = 0, prev = i;
    while (v[prev] == 1) {
      v[prev] = 2;
      prev = (prev - d + n) % n;
      ln++;
    }
    if (v[prev] == 2) {
      cycle = 1;
      break;
    }
    mx = max(mx, ln);
  }
  if (cycle) {
    mx = -1;
  }
  cout << mx << "\n";
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
