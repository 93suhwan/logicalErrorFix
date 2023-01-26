#include <bits/stdc++.h>
using namespace std;
long long modInverse(long long a, long long b) {
  return 1 < a ? b - modInverse(b % a, a) * b / a : 1;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
int solve_odd(long long searched, long long offset,
              vector<pair<long long, long long>> idx[], long long l,
              long long r) {
  int change_idx;
  if (searched > 0) {
    searched = (searched + 1) / 2 + offset;
    pair<long long, long long> search_key = make_pair(searched, l);
    change_idx = idx[0][lower_bound(idx[0].begin(), idx[0].end(), search_key) -
                        idx[0].begin()]
                     .second;
  } else {
    searched = (searched - 1) / 2 + offset;
    pair<long long, long long> search_key = make_pair(searched, l);
    change_idx = idx[1][lower_bound(idx[1].begin(), idx[1].end(), search_key) -
                        idx[1].begin()]
                     .second;
  }
  return change_idx;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  long long pref[n + 1];
  pref[0] = 0;
  for (int k = 1; k <= n; k++) {
    pref[k] = pref[k - 1];
    int d = 0;
    if (s[k - 1] == '+')
      d = 1;
    else
      d = -1;
    if ((k & 1) == 0) d = -d;
    pref[k] += d;
  }
  vector<pair<long long, long long>> idx[2];
  for (int k = 1; k <= n; k++) {
    if (pref[k] > pref[k - 1]) {
      idx[0].push_back({pref[k], k});
    } else {
      idx[1].push_back({pref[k], k});
    }
  }
  sort(idx[0].begin(), idx[0].end());
  sort(idx[1].begin(), idx[1].end());
  for (int k = 0; k < m; k++) {
    long long l, r;
    cin >> l >> r;
    long long diff = pref[r] - pref[l - 1];
    if (diff == 0) {
      cout << "0\n";
      continue;
    }
    if (l == r) {
      cout << "1\n";
      continue;
    }
    if (diff % 2 == 0) {
      cout << 2 << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
