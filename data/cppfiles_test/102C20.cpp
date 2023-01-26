#include <bits/stdc++.h>
using namespace std;
int recur_depth = 0;
const long long sz = 50, mod = 998244353;
long long pos[sz], k, h, A, n, lev[sz], ok, pw[sz], half;
unordered_map<long long, unordered_map<long long, vector<int>>> rest;
vector<long long> other;
long long iter;
void solve1(long long x, long long msk, long long hsh) {
  if (ok) return;
  if (x == 1) {
    long long frst;
    for (long long i = 0; i < half; ++i) {
      if (msk >> i & 1) frst = i;
    }
    vector<int> v;
    for (long long i = 0; i < half; ++i) v.push_back(pos[i]);
    rest[frst][hsh] = v;
    return;
  }
  vector<pair<int, int>> lst;
  long long x1 = -1;
  for (long long i = 0; i < half; ++i) {
    if ((msk >> i) & 1) {
      if (x1 == -1)
        x1 = i;
      else {
        lst.push_back(make_pair(x1, i));
        x1 = -1;
      }
    }
  }
  long long lim = 1 << lst.size();
  int pos2[half];
  for (long long i = 0; i < lim; ++i) {
    long long nmsk = msk, cur = hsh;
    for (long long j = 0; j < half; ++j) pos2[j] = pos[j];
    for (long long j = 0; j < lst.size(); ++j) {
      auto& [a, b] = lst[j];
      if ((i >> j) & 1) {
        nmsk ^= (1 << a);
        pos[a] = lev[x], cur = (cur + (a + 1) * pw[pos[a]]) % mod;
      } else {
        nmsk ^= (1 << b);
        pos[b] = lev[x], cur = (cur + (b + 1) * pw[pos[b]]) % mod;
        ;
      }
    }
    solve1(x - 1, nmsk, cur);
    for (long long j = 0; j < half; ++j) pos[j] = pos2[j];
  }
}
inline long long make_Hash(long long hsh, long long p1, long long p2) {
  hsh = (hsh + p1 * pw[1]) % mod;
  hsh = (hsh + p2 * pw[2]) % mod;
  return hsh;
}
inline bool doExist(long long hsh, long long ph) {
  auto it = rest[ph].find(hsh);
  return it != rest[ph].end();
}
void solve2(long long x, long long msk, long long hsh) {
  if (ok) return;
  if (x == 1) {
    long long frst;
    for (int i = half; i < n; i++) {
      if ((msk >> i) & 1) frst = i;
    }
    for (long long i = 0; i < half; ++i) {
      long long cur = make_Hash(hsh, frst + 1, i + 1), need = (h - cur);
      if (need < 0) need += mod;
      if (!doExist(need, i)) continue;
      auto it = rest[i].find(need);
      for (long long j = 0; j < half; ++j) pos[j] = it->second[j];
      pos[i] = 2, pos[frst] = 1, ok = 1;
      return;
    }
    for (long long i = 0; i < half; ++i) {
      long long cur = make_Hash(hsh, i + 1, frst + 1), need = (h - cur);
      if (need < 0) need += mod;
      if (!doExist(need, i)) continue;
      auto it = rest[i].find(need);
      for (long long j = 0; j < half; ++j) pos[j] = it->second[j];
      pos[i] = 1, pos[frst] = 2, ok = 1;
      return;
    }
    return;
  }
  vector<pair<int, int>> lst;
  long long x1 = -1;
  for (int i = half; i < n; i++) {
    if ((msk >> i) & 1) {
      if (x1 == -1)
        x1 = i;
      else {
        lst.push_back(make_pair(x1, i));
        x1 = -1;
      }
    }
  }
  long long lim = 1 << lst.size();
  int pos2[n];
  for (long long i = 0; i < lim; ++i) {
    long long nmsk = msk, cur = hsh;
    for (int j = half; j < n; j++) pos2[j] = pos[j];
    for (long long j = 0; j < lst.size(); ++j) {
      auto& [a, b] = lst[j];
      if ((i >> j) & 1) {
        nmsk ^= (1 << a);
        pos[a] = lev[x], cur = (cur + (a + 1) * pw[pos[a]]) % mod;
      } else {
        nmsk ^= (1 << b);
        pos[b] = lev[x], cur = (cur + (b + 1) * pw[pos[b]]) % mod;
        ;
      }
    }
    solve2(x - 1, nmsk, cur);
    if (ok) return;
    for (int j = half; j < n; j++) pos[j] = pos2[j];
  }
}
int main() {
  cin >> k >> A >> h;
  pw[0] = 1;
  for (long long i = 1; i <= sz - 1; ++i) pw[i] = (pw[i - 1] * A) % mod;
  lev[0] = 1, lev[1] = 2;
  for (long long i = 2; i <= k; i++) lev[i] = (1LL << (i - 1)) + 1;
  n = 1LL << k, half = n / 2;
  solve1(k, (1LL << half) - 1, 0);
  solve2(k, ((1LL << n) - 1) ^ ((1LL << half) - 1), 0);
  if (ok) {
    for (long long i = 0; i < n; ++i) printf("%lld ", pos[i]);
    printf("\n");
  } else
    printf("-1\n");
  return 0;
}
