#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
long long a[maxn], n;
char b[maxn];
long long st[maxn], top, ans, L[maxn];
int vis[maxn], x, p[maxn], minn[maxn];
void oula() {
  for (int i = 2; i < maxn; i++) {
    if (vis[i] == 0) p[++x] = i, minn[i] = i;
    for (int j = 1; j <= x && i * p[j] < maxn; j++) {
      vis[i * p[j]] = 1;
      minn[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}
long long num[maxn];
long long pos[maxn][21];
int main() {
  oula();
  scanf("%lld", &n);
  for (int i = (1); i <= (n); ++i) scanf("%lld", &a[i]);
  scanf("%s", b + 1);
  for (int i = 1; i <= n; i++) {
    long long temp = a[i];
    if (b[i] == '*') {
      L[i] = i;
      while (temp > 1) {
        long long t = minn[temp];
        num[t]++;
        pos[t][num[t]] = i;
        temp /= t;
      }
      if (temp > 1) num[temp]++, pos[temp][num[temp]] = i;
    } else {
      long long pos_L = 1e9;
      map<int, int> mp;
      while (temp > 1) {
        long long t = minn[temp];
        mp[t]++;
        temp /= t;
      }
      if (temp > 1) mp[temp]++;
      for (auto fr : mp) {
        long long t = fr.first;
        long long ci = fr.second;
        if (num[t] - ci + 1 >= 1) pos_L = min(pos_L, pos[t][num[t] - ci + 1]);
        num[t] -= ci;
      }
    }
  }
  int now = n;
  while (1) {
    long long pos_l = L[now];
    if (pos_l == 0 || pos_l >= 1e9) break;
    ans = ans + (n - now + 1);
    now = pos_l - 1;
  }
  printf("%lld", ans);
  return 0;
}
