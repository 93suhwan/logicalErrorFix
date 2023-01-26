#include <bits/stdc++.h>
using namespace std;
const long long P = 1e9 + 7, N = 2005;
long long f[N][6], k;
long long n;
map<string, long long> M;
map<long long, long long> S;
set<long long> siz;
vector<long long> slove(long long x, long long dep) {
  if (siz.find(x) == siz.end()) {
    vector<long long> ret;
    for (long long i = 0; i < 6; i++) ret.push_back(f[dep][i]);
    return ret;
  }
  if (dep == 1) {
    vector<long long> ret;
    for (long long i = 0; i < 6; i++) ret.push_back(1);
    if (S.find(x) != S.end()) {
      long long col = S[x];
      for (long long i = 0; i < 6; i++)
        if (i != col) ret[i] = 0;
    }
    return ret;
  }
  vector<long long> l = slove(x * 2, dep - 1), r = slove(x * 2 + 1, dep - 1);
  vector<long long> ret(6);
  for (long long i = 0; i < 6; i++) ret[i] = 0;
  for (long long c = 0; c < 6; c++)
    for (long long lc = 0; lc < 6; lc++)
      for (long long rc = 0; rc < 6; rc++) {
        if (c == lc || c == rc) continue;
        if ((c ^ lc) == 1 || (c ^ rc) == 1) continue;
        ret[c] = (1ll * l[lc] * r[rc] + ret[c]) % P;
      }
  if (S.find(x) != S.end()) {
    long long col = S[x];
    for (long long i = 0; i < 6; i++)
      if (i != col) ret[i] = 0;
  }
  return ret;
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> k;
  for (long long i = 0; i < 6; i++) f[1][i] = 1;
  for (long long i = 2; i <= k; i++) {
    for (long long x = 0; x < 6; x++)
      for (long long l = 0; l < 6; l++)
        for (long long r = 0; r < 6; r++) {
          if (x == l || x == r) continue;
          if ((x ^ l) == 1 || (x ^ r) == 1) continue;
          f[i][x] = (1ll * f[i - 1][l] * f[i - 1][r] + f[i][x]) % P;
        }
  }
  M["white"] = 0;
  M["yellow"] = 1;
  M["green"] = 2;
  M["blue"] = 3;
  M["red"] = 4;
  M["orange"] = 5;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    string s;
    long long x;
    cin >> x >> s;
    S[x] = M[s];
    while (x) {
      siz.insert(x);
      x /= 2;
    }
  }
  vector<long long> ans = slove(1, k);
  long long ANS = 0;
  for (auto x : ans) ANS = (ANS + x) % P;
  cout << ANS << endl;
  return 0;
}
