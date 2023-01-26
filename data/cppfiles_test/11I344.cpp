#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long bit = 32;
vector<long long> primes;
void sieve(long long n) {
  vector<long long> vis(n + 10, 0);
  for (long long i = 2; i * i <= n; i++) {
    if (!vis[i]) {
      for (long long j = i * i; j <= n; j += i) {
        vis[j] = 1;
      }
    }
  }
  for (long long i = 2; i <= n; i++) {
    if (!vis[i]) primes.push_back(i);
  }
}
long long factorize(long long n) {
  long long cnt = 0;
  for (auto x : primes) {
    if (n < x) break;
    while (n % x == 0) {
      n = n / x;
      cnt++;
    }
  }
  if (n > 1) cnt++;
  return cnt;
}
bool compare(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
}
void remove_duplicates(vector<long long> &v) {
  long long i = 0;
  while (i < v.size() - 1) {
    if (v[i] == v[i + 1])
      v.erase(v.begin() + i, v.begin() + i + 1);
    else
      i++;
  }
  return;
}
unordered_map<long long, unordered_map<long long, long long>> ncrmap;
long long nCr(long long n, long long r) {
  if (ncrmap[n].find(ncrmap[n][r]) == ncrmap[n].end()) {
    if (n < r) return ncrmap[n][r] = 0;
    if (n == r) return ncrmap[n][r] = 1;
    if (r == 1) return ncrmap[n][r] = n;
    if (r == 0) return ncrmap[n][r] = 1;
    ncrmap[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
  }
  return ncrmap[n][r];
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  if (x == 1) return 1;
  if (y % 2 == 1) return ((x % mod) * ((power(x, y - 1) % mod))) % mod;
  long long a = power(x, y / 2) % mod;
  return ((a * a) % mod);
}
bool compare1(pair<long long, string> a, pair<long long, string> b) {
  long long d1 = -1 * a.first + a.second.size();
  long long d2 = -1 * b.first + b.second.size();
  if (d1 < d2)
    return 1;
  else if (d1 == d2) {
    if (a.first > b.first)
      return 1;
    else
      return 0;
  } else
    return 0;
}
void solve() {
  long long n;
  cin >> n;
  vector<string> dict(n);
  for (auto &x : dict) cin >> x;
  vector<pair<long long, string>> a, b, c, d, e;
  for (auto &x : dict) {
    long long cnt = 0;
    for (auto &y : x) {
      if (y == 'a') cnt++;
    }
    a.push_back({cnt, x});
  }
  for (auto &x : dict) {
    long long cnt = 0;
    for (auto &y : x) {
      if (y == 'b') cnt++;
    }
    b.push_back({cnt, x});
  }
  for (auto &x : dict) {
    long long cnt = 0;
    for (auto &y : x) {
      if (y == 'c') cnt++;
    }
    c.push_back({cnt, x});
  }
  for (auto &x : dict) {
    long long cnt = 0;
    for (auto &y : x) {
      if (y == 'd') cnt++;
    }
    d.push_back({cnt, x});
  }
  for (auto &x : dict) {
    long long cnt = 0;
    for (auto &y : x) {
      if (y == 'e') cnt++;
    }
    e.push_back({cnt, x});
  }
  sort(a.begin(), a.end(), compare1);
  sort(b.begin(), b.end(), compare1);
  sort(c.begin(), c.end(), compare1);
  sort(d.begin(), d.end(), compare1);
  sort(e.begin(), e.end(), compare1);
  long long mxa = 0, mxb = 0, mxc = 0, mxd = 0, mxe = 0;
  long long sz, occ, cnt;
  sz = 0, occ = 0, cnt = 0;
  for (auto &x : a) {
    sz += x.second.size();
    occ += x.first;
    cnt++;
    if (occ > (sz - occ)) {
      mxa = mxa > cnt ? mxa : cnt;
    }
  }
  sz = 0, occ = 0, cnt = 0;
  for (auto &x : b) {
    sz += x.second.size();
    occ += x.first;
    cnt++;
    if (occ > (sz - occ)) {
      mxb = mxb > cnt ? mxb : cnt;
    }
  }
  sz = 0, occ = 0, cnt = 0;
  for (auto &x : c) {
    sz += x.second.size();
    occ += x.first;
    cnt++;
    if (occ > (sz - occ)) {
      mxc = mxc > cnt ? mxc : cnt;
    }
  }
  sz = 0, occ = 0, cnt = 0;
  for (auto &x : d) {
    sz += x.second.size();
    occ += x.first;
    cnt++;
    if (occ > (sz - occ)) {
      mxd = mxd > cnt ? mxd : cnt;
    }
  }
  sz = 0, occ = 0, cnt = 0;
  for (auto &x : e) {
    sz += x.second.size();
    occ += x.first;
    cnt++;
    if (occ > (sz - occ)) {
      mxe = mxe > cnt ? mxe : cnt;
    }
  }
  long long ans = 0;
  ans = ans > mxa ? ans : mxa;
  ans = ans > mxb ? ans : mxb;
  ans = ans > mxc ? ans : mxc;
  ans = ans > mxd ? ans : mxd;
  ans = ans > mxe ? ans : mxe;
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  cout << "\n";
  while (t--) {
    solve();
  }
  return 0;
}
