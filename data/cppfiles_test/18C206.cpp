#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10;
const long long inf = 0x3f3f3f3f;
const long long INF = 1ll << 62;
inline long long rd() {
  long long x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
void slove() {
  long long n = rd(), m = rd();
  map<long long, long long> mpp;
  vector<long long> vis(n * 2 + 10), vis2(n * 2 + 10);
  vector<pair<long long, long long> > mp;
  for (long long i = 1; i <= m; i++) {
    long long a = rd(), b = rd();
    if (a > b) swap(a, b);
    mp.push_back({a, b});
    mpp[a] = b;
    mpp[b] = a;
    vis[a] = 1;
    vis[b] = 1;
  }
  vector<long long> ve;
  for (long long i = 1; i <= n * 2; i++) {
    if (!vis[i]) ve.push_back(i);
  }
  long long l = 0, r = n - m;
  for (long long i = 0; i < n - m; i++) {
    mpp[ve[l]] = ve[r];
    mpp[ve[r]] = ve[l];
    mp.push_back({ve[l++], ve[r++]});
  }
  sort(mp.begin(), mp.end());
  long long res = 0;
  for (long long i = 0; i < mp.size(); i++) {
    long long f = mp[i].first, s = mp[i].second;
    if (f > s) swap(f, s);
    vis2[f] = 1;
    vis2[s] = 1;
    for (long long j = f + 1; j < s; j++) {
      if (!vis2[j] && (mpp[j] < f || mpp[j] > s)) res++;
    }
  }
  printf("%lld\n", res);
}
signed main() {
  long long t = rd();
  while (t--) {
    slove();
  }
  return 0;
}
