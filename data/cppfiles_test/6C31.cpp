#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937_64 rnd;
const long long maxn = 1e5 + 50;
const long long mod = 1e9 + 7;
const long long base = 1e13;
const long long magic = 2000;
vector<long long> adj[maxn];
void dosth() {
  for (int i = 1; i < maxn; i++) {
    for (int j = i; j < maxn; j += i) {
      adj[j].push_back(i);
    }
  }
}
long long val[maxn];
long long a[maxn];
vector<long long> gr[maxn];
long long ph[maxn];
long long cnt1[maxn];
long long get(vector<long long> vt) {
  long long ans = 0;
  for (auto to : vt) {
    for (auto h : adj[to]) {
      ans += (cnt1[h] * 2 + 1) * ph[h];
      cnt1[h]++;
    }
  }
  for (auto to : vt)
    for (auto h : adj[to]) cnt1[h] = 0;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  dosth();
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < maxn; i++) {
    ph[i] = i;
    for (auto to : adj[i]) {
      if (i == to) continue;
      ph[i] -= ph[to];
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long cnt = 0;
    vector<long long> vt;
    for (int j = i; j <= n; j += i) vt.push_back(a[j]);
    ans = (ans + (get(vt) * ph[i])) % mod;
  }
  cout << ans << "\n";
}
