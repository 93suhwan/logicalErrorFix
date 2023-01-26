#include <bits/stdc++.h>
using namespace std;
long long T, n, dp[5005];
long long f[20][5005], LOG[5005];
string s;
long long bk[5005], rk[5005], tp[5005], sa[5005], hei[5005], M;
void init_st() {
  LOG[0] = -1;
  for (long long i = 1; i < 5005; i++) LOG[i] = LOG[i >> 1] + 1;
  for (long long i = 1; i <= n; i++) f[0][i] = hei[i];
  for (long long i = 1; i <= 18; i++) {
    for (long long j = 1; j <= n; j++) {
      if (j + (1ll << (i - 1)) > n) break;
      f[i][j] = min(f[i - 1][j], f[i - 1][j + (1ll << (i - 1))]);
    }
  }
}
long long rmq(long long x, long long y) {
  if (x > y) swap(x, y);
  long long k = LOG[y - x + 1];
  return min(f[k][x], f[k][y - (1ll << k) + 1]);
}
void sort_sa() {
  for (long long i = 0; i <= M; i++) bk[i] = 0;
  for (long long i = 1; i <= n; i++) bk[rk[tp[i]]]++;
  for (long long i = 1; i <= M; i++) bk[i] += bk[i - 1];
  for (long long i = n; i >= 1; i--) sa[bk[rk[tp[i]]]--] = tp[i];
}
void get_sa() {
  for (long long i = 1; i <= n; i++) {
    rk[i] = s[i];
    tp[i] = i;
  }
  M = 195;
  sort_sa();
  for (long long w = 1; w <= n; w <<= 1) {
    long long cnt = 0;
    for (long long i = n - w + 1; i <= n; i++) tp[++cnt] = i;
    for (long long i = 1; i <= n; i++)
      if (sa[i] - w > 0) tp[++cnt] = sa[i] - w;
    sort_sa();
    swap(rk, tp);
    cnt = 0;
    rk[sa[0]] = 0;
    for (long long i = 1; i <= n; i++)
      rk[sa[i]] =
          (tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + w] == tp[sa[i - 1] + w])
              ? cnt
              : ++cnt;
    M = cnt + 1;
  }
  long long k = 0;
  for (long long j, i = 1; i <= n; i++) {
    if (k) k--;
    j = sa[rk[i] - 1];
    while (s[i + k] == s[j + k]) k++;
    hei[rk[i]] = k;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> s;
    s = ' ' + s;
    get_sa();
    s += '0';
    dp[0] = 0;
    init_st();
    for (long long i = 1; i <= n; i++) {
      dp[i] = n - i + 1;
      for (long long pre, j = 1; j < i; j++) {
        pre = rmq(min(rk[i], rk[j]) + 1, max(rk[i], rk[j]));
        if (s[i + pre] > s[j + pre]) {
          dp[i] = max(dp[i], dp[j] + (n - i + 1) - pre);
        }
      }
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
  }
  return 0;
}
