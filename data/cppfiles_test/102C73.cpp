#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long k, A, h;
  cin >> k >> A >> h;
  long long total_teams = 1 << (k - 1);
  vector<vector<pair<long long, long long> > > v1(2), v2(2);
  long long states = binpow(2, total_teams - 1, mod);
  for (long long x = 0; x < states; x++) {
    long long hash1 = 0, hash2 = 0;
    vector<long long> remain;
    for (long long y = 1; y <= total_teams; y++) remain.push_back(y);
    for (long long y = total_teams - 2; y >= 0; y--) {
      if (x & (1 << y)) {
        remain.push_back(remain[(total_teams - 2 - y) * 2 + 1]);
        hash1 = (hash1 +
                 remain[(total_teams - 2 - y) * 2] *
                     binpow(A, (1 << ((long long)log2(y + 1) + 1)) + 1, mod)) %
                mod;
        hash2 = (hash2 +
                 (remain[(total_teams - 2 - y) * 2] + total_teams) *
                     binpow(A, (1 << ((long long)log2(y + 1) + 1)) + 1, mod)) %
                mod;
      } else {
        remain.push_back(remain[(total_teams - 2 - y) * 2]);
        hash1 = (hash1 +
                 remain[(total_teams - 2 - y) * 2 + 1] *
                     binpow(A, (1 << ((long long)log2(y + 1) + 1)) + 1, mod)) %
                mod;
        hash2 = (hash2 +
                 (remain[(total_teams - 2 - y) * 2 + 1] + total_teams) *
                     binpow(A, (1 << ((long long)log2(y + 1) + 1)) + 1, mod)) %
                mod;
      }
    }
    v1[0].push_back(make_pair(
        ((hash1 + (remain[remain.size() - 1] * binpow(A, 2, mod)) % mod) % mod),
        x));
    v1[1].push_back(make_pair(
        ((hash1 + (remain[remain.size() - 1] * binpow(A, 1, mod)) % mod) % mod),
        x));
    v2[0].push_back(make_pair(
        ((hash2 +
          ((remain[remain.size() - 1] + total_teams) * binpow(A, 2, mod)) %
              mod) %
         mod),
        x));
    v2[1].push_back(make_pair(
        ((hash2 +
          ((remain[remain.size() - 1] + total_teams) * binpow(A, 1, mod)) %
              mod) %
         mod),
        x));
  }
  sort(v1[0].begin(), v1[0].end());
  sort(v2[0].begin(), v2[0].end());
  sort(v1[1].begin(), v1[1].end());
  sort(v2[1].begin(), v2[1].end());
  for (long long x = 0; x < 2; x++) {
    for (long long y = 0; y < states; y++) {
      long long h1, h2;
      h1 = h - v1[x][y].first;
      h2 = h1 + mod;
      auto it1 = lower_bound(v2[x ^ 1].begin(), v2[x ^ 1].end(),
                             make_pair(h1, numeric_limits<long long>::min()));
      auto it2 = lower_bound(v2[x ^ 1].begin(), v2[x ^ 1].end(),
                             make_pair(h2, numeric_limits<long long>::min()));
      if ((it1 != v2[x ^ 1].end() && it1->first == h1) ||
          (it2 != v2[x ^ 1].end() && it2->first == h2)) {
        vector<long long> ans(binpow(2, k, mod) + 1);
        vector<long long> remain1, remain2;
        for (long long z = 1; z <= total_teams; z++)
          remain1.push_back(z), remain2.push_back(z);
        long long y2;
        if ((it1 != v2[x ^ 1].end() && it1->first == h1))
          y2 = it1->second;
        else
          y2 = it2->second;
        long long y1 = v1[x][y].second;
        for (long long z = total_teams - 2; z >= 0; z--) {
          if (y1 & (1 << z)) {
            remain1.push_back(remain1[(total_teams - 2 - z) * 2 + 1]);
            ans[remain1[(total_teams - 2 - z) * 2]] =
                (1 << ((long long)log2(z + 1) + 1)) + 1;
          } else {
            remain1.push_back(remain1[(total_teams - 2 - z) * 2]);
            ans[remain1[(total_teams - 2 - z) * 2 + 1]] =
                (1 << ((long long)log2(z + 1) + 1)) + 1;
          }
          if (y2 & (1 << z)) {
            remain2.push_back(remain2[(total_teams - 2 - z) * 2 + 1]);
            ans[remain2[(total_teams - 2 - z) * 2] + total_teams] =
                (1 << ((long long)log2(z + 1) + 1)) + 1;
          } else {
            remain2.push_back(remain2[(total_teams - 2 - z) * 2]);
            ans[remain2[(total_teams - 2 - z) * 2 + 1] + total_teams] =
                (1 << ((long long)log2(z + 1) + 1)) + 1;
          }
        }
        if (x == 1) {
          ans[remain1[remain1.size() - 1]] = 1;
          ans[remain2[remain2.size() - 1] + total_teams] = 2;
        } else {
          ans[remain1[remain1.size() - 1]] = 2;
          ans[remain2[remain2.size() - 1] + total_teams] = 1;
        }
        for (long long z = 1; z <= binpow(2, k, mod); z++)
          cout << ans[z] << " ";
        cout << "\n";
        return;
      }
    }
  }
  cout << -1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
