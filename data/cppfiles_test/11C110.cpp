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
    a.push_back({2 * cnt - x.size(), x});
  }
  for (auto &x : dict) {
    long long cnt = 0;
    for (auto &y : x) {
      if (y == 'b') cnt++;
    }
    b.push_back({2 * cnt - x.size(), x});
  }
  for (auto &x : dict) {
    long long cnt = 0;
    for (auto &y : x) {
      if (y == 'c') cnt++;
    }
    c.push_back({2 * cnt - x.size(), x});
  }
  for (auto &x : dict) {
    long long cnt = 0;
    for (auto &y : x) {
      if (y == 'd') cnt++;
    }
    d.push_back({2 * cnt - x.size(), x});
  }
  for (auto &x : dict) {
    long long cnt = 0;
    for (auto &y : x) {
      if (y == 'e') cnt++;
    }
    e.push_back({2 * cnt - x.size(), x});
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());
  sort(e.begin(), e.end());
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  reverse(c.begin(), c.end());
  reverse(d.begin(), d.end());
  reverse(e.begin(), e.end());
  vector<long long> psa(n), psb(n), psc(n), psd(n), pse(n);
  psa[0] = a[0].first;
  for (long long i = 1; i < n; i++) psa[i] = psa[i - 1] + a[i].first;
  psb[0] = b[0].first;
  for (long long i = 1; i < n; i++) psb[i] = psb[i - 1] + b[i].first;
  psc[0] = c[0].first;
  for (long long i = 1; i < n; i++) psc[i] = psc[i - 1] + c[i].first;
  psd[0] = d[0].first;
  for (long long i = 1; i < n; i++) psd[i] = psd[i - 1] + d[i].first;
  pse[0] = e[0].first;
  for (long long i = 1; i < n; i++) pse[i] = pse[i - 1] + e[i].first;
  long long mxa = -1, mxb = -1, mxc = -1, mxd = -1, mxe = -1;
  for (long long i = n - 1; i >= 0; i--)
    if (psa[i] > 0) {
      mxa = i + 1;
      break;
    }
  for (long long i = n - 1; i >= 0; i--)
    if (psb[i] > 0) {
      mxb = i + 1;
      break;
    }
  for (long long i = n - 1; i >= 0; i--)
    if (psc[i] > 0) {
      mxc = i + 1;
      break;
    }
  for (long long i = n - 1; i >= 0; i--)
    if (psd[i] > 0) {
      mxd = i + 1;
      break;
    }
  for (long long i = n - 1; i >= 0; i--)
    if (pse[i] > 0) {
      mxe = i + 1;
      break;
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
