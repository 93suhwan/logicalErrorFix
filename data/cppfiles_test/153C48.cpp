#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int modmult(int x, int y) { return (x * int64_t(y)) % MOD; }
template <class T>
void chmin(T& x, T y) {
  if (y < x) x = y;
}
int64_t solve(const vector<string>& s) {
  int n = s.size();
  vector<array<int, 26>> cnt(n);
  for (int i = 0; i < n; ++i) {
    fill(cnt[i].begin(), cnt[i].end(), 0);
    for (char c : s[i]) {
      cnt[i][c - 'a']++;
    }
  }
  vector<int> sub_all(1 << n, 0);
  for (int i = 1; i < (1 << n); ++i) {
    array<int, 26> c;
    fill(c.begin(), c.end(), 1e9);
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        for (int k = 0; k < 26; ++k) {
          chmin(c[k], cnt[j][k]);
        }
      }
    }
    sub_all[i] = 1;
    for (int j = 0; j < 26; ++j) {
      sub_all[i] = modmult(sub_all[i], c[j] + 1);
    }
  }
  vector<int> f = sub_all;
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      if ((mask >> i) & 1) {
        f[mask] -= f[mask ^ (1 << i)];
        if (f[mask] < 0) f[mask] += MOD;
      }
    }
  }
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (!(__builtin_popcount(mask) & 1)) {
      if (f[mask] != 0) {
        f[mask] = MOD - f[mask];
      }
    }
  }
  int64_t ans = 0;
  for (int mask = 1; mask < (1 << n); ++mask) {
    vector<int> inds;
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        inds.push_back(i);
      }
    }
    int sub_ans = f[mask];
    int64_t sum_inds = 0;
    for (int i : inds) {
      sum_inds += (i + 1);
    }
    ans ^= (sum_inds * int64_t(inds.size()) * sub_ans);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  cout << solve(s) << endl;
}
