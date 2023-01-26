#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5002;
const long long mod = 998244353;
long long fact[MAXN];
long long rfact[MAXN];
long long fastpow(long long x, long long p) {
  if (p == 0) return 1;
  if (p == 1) return x;
  long long t = fastpow(x, p / 2);
  t *= t;
  t %= mod;
  if (p % 2 == 1) {
    t *= x;
    t %= mod;
  }
  return t;
}
void precompute() {
  fact[0] = 1;
  rfact[0] = fastpow(fact[0], mod - 2);
  for (long long i = 1; i < MAXN; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
    rfact[i] = fastpow(fact[i], mod - 2);
  }
}
long long comb(long long n, long long k) {
  if (k > n) return 0;
  long long ret = fact[n];
  ret *= rfact[k];
  ret %= mod;
  ret *= rfact[n - k];
  ret %= mod;
  return ret;
}
vector<pair<long long, long long> > segments;
long long ans = 1, n, k;
long long pref[MAXN];
string s;
int main() {
  precompute();
  cin >> n >> k;
  long long l, r = -1, cnt1 = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    pref[i + 1] = pref[i] + (s[i] == '1');
  }
  for (l = 0; l < s.size(); l++) {
    bool moved_r = false;
    while (r + 1 < s.size() && cnt1 + (s[r + 1] == '1') <= k) {
      r++;
      cnt1 += (s[r] == '1');
      moved_r = 1;
    }
    if (moved_r && cnt1 == k) segments.push_back({l, r});
    if (s[l] == '1') cnt1--;
  }
  for (int i = 0; i < segments.size(); i++) {
    ans += comb(segments[i].second - segments[i].first + 1, k) + mod - 1;
    ans %= mod;
  }
  for (int i = 1; i < segments.size(); i++) {
    int l1 = segments[i].first, r1 = segments[i - 1].second;
    if (l1 > r1) continue;
    ans += mod - comb(r1 - l1 + 1, pref[r1 + 1] - pref[l1]) + 1;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
