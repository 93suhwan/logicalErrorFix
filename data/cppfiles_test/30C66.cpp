#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 5;
long long n, a[maxn], par[maxn], sz[maxn];
bool mrk[maxn];
vector<int> prm[maxn];
map<pair<int, int>, bool> mp;
long long get_par(long long v) {
  if (v == par[v]) return v;
  par[v] = get_par(par[v]);
  return par[v];
}
void merge(long long u, long long v) {
  u = get_par(u);
  v = get_par(v);
  if (u == v) return;
  if (sz[u] < sz[v]) swap(u, v);
  sz[u] += sz[v];
  par[v] = u;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  for (long long i = 1; i < maxn; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  for (long long i = 2; i < maxn; i++) {
    if (mrk[i]) continue;
    for (long long j = i + i; j < maxn; j += i) {
      mrk[j] = 1;
      prm[j].push_back(i);
    }
    prm[i].push_back(i);
  }
  long long q;
  cin >> n >> q;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    long long v = prm[a[i]][0];
    for (long long j : prm[a[i]]) {
      merge(j, v);
    }
  }
  for (long long i = 2; i < maxn; i++) {
    if (mrk[i]) continue;
    get_par(i);
  }
  for (long long i = 0; i < n; i++) {
    pair<int, int> p;
    for (long long j : prm[a[i] + 1]) {
      p.first = par[j];
      for (long long k : prm[a[i] + 1]) {
        p.second = par[k];
        mp[p] = 1;
      }
      for (long long k : prm[a[i]]) {
        p.second = par[k];
        mp[p] = 1;
      }
    }
    for (long long j : prm[a[i]]) {
      p.first = par[j];
      for (long long k : prm[a[i] + 1]) {
        p.second = par[k];
        mp[p] = 1;
      }
    }
  }
  while (q--) {
    long long i, j;
    cin >> i >> j;
    i--;
    j--;
    long long p1 = par[prm[a[i]][0]];
    long long p2 = par[prm[a[j]][0]];
    pair<int, int> p = {p1, p2};
    if (p1 == p2)
      cout << 0 << '\n';
    else if (mp[p])
      cout << 1 << '\n';
    else
      cout << 2 << '\n';
  }
}
