#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mod = 1e9 + 7, MAGIC = 100;
vector<int> fac[N];
vector<int> elem[N];
long long g[N];
int cnt[N];
long long solve(vector<int>& val) {
  vector<int> all;
  vector<int> distinct;
  for (int x : val) {
    if (cnt[x] == 0) {
      distinct.push_back(x);
    }
    ++cnt[x];
  }
  sort(distinct.begin(), distinct.end());
  all = distinct;
  for (int x : distinct) {
    for (int z : fac[x]) {
      if (cnt[z] == 0) {
        all.push_back(z);
      }
      cnt[z] += cnt[x];
    }
  }
  sort(all.begin(), all.end());
  reverse(all.begin(), all.end());
  for (int x : all) {
    cnt[x] = 1LL * cnt[x] * cnt[x] % mod;
  }
  long long ans = 0;
  for (int x : all) {
    int cur = cnt[x];
    ans = (ans + 1LL * x * cur) % mod;
    for (int z : fac[x]) {
      cnt[z] -= cur;
      if (cnt[z] < 0) cnt[z] += mod;
    }
    cnt[x] = 0;
  }
  return ans;
}
int main() {
  for (int i = 1; i < N; ++i) {
    for (int j = i + i; j < N; j += i) {
      fac[j].push_back(i);
    }
  }
  int maxi = 0, s = 0;
  for (int i = 2; i < N; ++i) {
    maxi = max(maxi, (int)fac[i].size());
    s += fac[i].size();
  }
  int n;
  scanf("%d", &n);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      elem[i].push_back(a[j]);
    }
  }
  long long ans = 0;
  for (int i = n; i >= 1; --i) {
    g[i] = solve(elem[i]);
    for (int j = i + i; j <= n; j += i) {
      g[i] -= g[j];
      if (g[i] < 0) g[i] += mod;
    }
    ans = (ans + g[i] * i) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
