#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 13;
const long long INF = 3e18 + 1;
const long long MOD = 1e9 + 7;
map<string, long long> ctn;
map<long long, set<long long>> ok;
void solve() {
  long long k, n;
  cin >> k >> n;
  ok[-1] = {};
  ctn["white"] = 0;
  ok[0] = {0, 5};
  ctn["green"] = 1;
  ok[1] = {1, 3};
  ctn["red"] = 2;
  ok[2] = {2, 4};
  ctn["blue"] = 3;
  ok[3] = {3, 1};
  ctn["orange"] = 4;
  ok[4] = {4, 2};
  ctn["yellow"] = 5;
  ok[5] = {5, 0};
  map<long long, long long> mp;
  map<long long, vector<long long>> res;
  for (long long i = 0; i < n; ++i) {
    long long u;
    string s;
    cin >> u >> s;
    mp[u] = ctn[s];
  }
  for (auto t : mp) {
    if ((1ll << (k - 1)) <= t.first && t.first < (1ll << k)) {
      vector<long long> y(6, 0);
      y[t.second] = 1;
      res[t.first] = y;
    }
  }
  long long val = 1;
  for (long long i = k - 2; i >= 0; --i) {
    vector<long long> del;
    for (auto t : mp) {
      if ((1ll << i) <= t.first && t.first < (1ll << (i + 1ll))) {
        vector<long long> yl(6, val), yr(6, val);
        if (mp.find(2 * t.first) != mp.end()) {
          yl = res[2 * t.first];
          del.push_back(2 * t.first);
        }
        if (mp.find(2 * t.first + 1) != mp.end()) {
          yr = res[2 * t.first + 1];
          del.push_back(2 * t.first + 1);
        }
        long long suml = 0;
        long long sumr = 0;
        for (long long j = 0; j < 6; ++j) {
          if (ok[t.second].find(j) == ok[t.second].end()) {
            suml += yl[j];
            sumr += yr[j];
            suml %= MOD;
            sumr %= MOD;
          }
        }
        vector<long long> e(6, 0);
        e[t.second] = (suml * sumr) % MOD;
        res[t.first] = e;
      }
    }
    for (auto t : del) {
      mp.erase(t);
    }
    del.clear();
    for (auto t : mp) {
      if ((1ll << (i + 1)) <= t.first && t.first < (1ll << (i + 2))) {
        del.push_back(t.first);
        vector<long long> yl(6, val), yr(6, val);
        if (t.first & 1) {
          yr = res[t.first];
          if (mp.find(t.first - 1) != mp.end()) {
            del.push_back(t.first - 1);
            yl = res[t.first - 1];
          }
        } else {
          yl = res[t.first];
          if (mp.find(t.first + 1) != mp.end()) {
            del.push_back(t.first + 1);
            yr = res[t.first + 1];
          }
        }
        vector<long long> x(6, 0);
        for (long long j = 0; j < 6; ++j) {
          long long suml = 0, sumr = 0;
          for (long long w = 0; w < 6; ++w) {
            if (ok[j].find(w) == ok[j].end()) {
              suml += yl[w];
              sumr += yr[w];
              suml %= MOD;
              sumr %= MOD;
            }
          }
          x[j] = (suml * sumr) % MOD;
        }
        res[t.first / 2] = x;
        mp[t.first / 2] = -1;
      }
    }
    for (auto t : del) {
      mp.erase(t);
    }
    val = (((val * 4) % MOD) * ((val * 4) % MOD)) % MOD;
  }
  long long sum = 0;
  for (auto t : res[1]) {
    sum += t;
    sum %= MOD;
  }
  cout << sum;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q = 1;
  while (q--) solve();
  return 0;
}
