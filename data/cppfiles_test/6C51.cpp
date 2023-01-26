#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
vector<int> divv[maxn];
void init() {
  for (int i = 1; i < maxn; ++i) {
    for (int j = i; j < maxn; j += i) {
      divv[j].push_back(i);
    }
  }
}
vector<int> usedPos;
bool vis[maxn];
long long gg[maxn], countt[maxn];
void clear() {
  for (int v : usedPos) {
    vis[v] = false;
    countt[v] = 0;
    gg[v] = 0;
  }
  usedPos.clear();
}
void update(int val, int cnt) {
  for (int v : divv[val]) {
    countt[v] += cnt;
    if (!vis[v]) {
      vis[v] = true;
      usedPos.push_back(v);
    }
  }
}
long long getans() {
  sort(usedPos.begin(), usedPos.end());
  for (int pos : usedPos) {
    gg[pos] = (long long)countt[pos] * countt[pos];
  }
  reverse(usedPos.begin(), usedPos.end());
  long long ans = 0;
  for (int pos : usedPos) {
    ans += (long long)pos * gg[pos] % mod;
    for (int npos : divv[pos]) {
      gg[npos] -= gg[pos];
    }
  }
  return ans % mod;
}
long long getv(vector<int>& vals) {
  sort(vals.begin(), vals.end());
  int sz = vals.size();
  for (int i = 0, j = 0; i < sz; i = j) {
    int cnt = 0;
    while (j < sz && vals[i] == vals[j]) {
      ++cnt;
      ++j;
    }
    update(vals[i], cnt);
  }
  long long ret = getans();
  clear();
  return ret;
}
int a[maxn];
long long f[maxn];
vector<int> tmp;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    tmp.clear();
    for (int j = i; j <= n; j += i) {
      tmp.push_back(a[j]);
    }
    f[i] = getv(tmp) % mod;
  }
  long long ans = 0;
  for (int i = n; i; --i) {
    for (int j = i + i; j <= n; j += i) {
      f[i] -= f[j];
    }
    f[i] %= mod;
    f[i] = (f[i] + mod) % mod;
    ans += (long long)f[i] * i % mod;
  }
  ans %= mod;
  cout << ans << endl;
  return 0;
}
