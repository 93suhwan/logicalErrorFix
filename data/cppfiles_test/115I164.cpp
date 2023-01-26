#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> v(n);
  for (auto &x : v) cin >> x;
  vector<long long> diff;
  for (long long i = 1; i < n; ++i) {
    diff.push_back(v[i] - v[i - 1]);
  }
  long long attacks = n;
  long long pow = ceill((long double)h / n);
  for (long long i = 0; i < diff.size(); ++i) {
    attacks--;
    if (diff[i] < pow) {
      h -= diff[i];
      pow = ceill((long double)h / attacks);
    } else {
      h -= pow;
    }
  }
  cout << pow << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc = 1;
  cin >> tc;
  for (long long t = 1; t <= tc; t++) {
    solve();
  }
}
