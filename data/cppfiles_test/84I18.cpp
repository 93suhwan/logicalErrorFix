#include <bits/stdc++.h>
template <typename T>
bool chkmin(T &a, T b) {
  return (b < a) ? a = b, 1 : 0;
}
template <typename T>
bool chkmax(T &a, T b) {
  return (b > a) ? a = b, 1 : 0;
}
long long ksm(long long a, long long b) {
  if (b == 0) return 1;
  long long ns = ksm(a, b >> 1);
  ns = ns * ns % 998244353;
  if (b & 1) ns = ns * a % 998244353;
  return ns;
}
using namespace std;
const int maxn = 100005;
vector<int> fc[maxn];
long long cnt[maxn];
long long cc[maxn];
long long ans = 0;
int l, r;
void ins(int pl, int tp) {
  for (auto v : fc[pl]) cc[v] = 0;
  for (auto v : fc[pl]) {
    int ls = (l + v - 1) / v, rs = r / v;
    cc[v] += rs - ls + 1;
    cnt[v] += cc[v] * tp;
    if (v >= l) ans += cc[v] * tp;
    for (auto s : fc[v]) {
      if (s == v) continue;
      cc[s] -= cc[v];
    }
    cc[v] = 0;
  }
  for (auto v : fc[pl]) cc[v] = 0;
}
void mv(int a, int b) {
  while (l > a) {
    ins(l - 1, 1);
    cnt[l - 1] += 1;
    l -= 1;
    ans += cnt[l];
  }
  while (r < b) {
    r += 1;
    ins(r, 1);
  }
  while (l < a) {
    ans -= cnt[l];
    cnt[l] -= 1;
    l += 1;
    ins(l - 1, -1);
  }
  while (r > b) {
    ins(r, -1);
    r -= 1;
  }
}
long long dp[20][maxn * 2];
void calc(int t, int al, int ar, int bl, int br) {
  if (bl > br) return;
  int bm = (bl + br) >> 1;
  long long nans = 1e18;
  int pl = -1;
  for (int j = al; j <= ar; j++) {
    mv(j + 1, bm);
    if (chkmin(nans, ans + dp[t - 1][j])) pl = j;
  }
  chkmin(dp[t][bm], nans);
  calc(t, al, pl, bl, bm - 1);
  calc(t, pl, ar, bm + 1, br);
}
int main() {
  for (int i = maxn - 1; i >= 1; i--)
    for (int j = i; j < maxn; j += i) fc[j].push_back(i);
  l = 1, r = 1;
  ins(1, 1);
  for (int i = 1; i < 17; i++) {
    if (i == 1) {
      for (int j = 1; j < maxn; j++) {
        mv(1, j);
        dp[i][j] = ans;
      }
    } else {
      l = r = 1;
      memset(cnt, 0, sizeof(cnt));
      cnt[1] = 1;
      ans = 1;
      int p = 0;
      for (int j = 1; j < maxn; j++) {
        mv(l, j);
        long long nans = dp[i - 1][l - 1] + ans;
        while (l < j) {
          mv(l + 1, j);
          long long na = dp[i - 1][l - 1] + ans;
          if (na > nans) {
            mv(l - 1, j);
            break;
          }
        }
        dp[i][j] = dp[i - 1][l - 1] + ans;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    long long ans = 0;
    if (k >= 17)
      ans = n;
    else
      ans = dp[k][n];
    printf("%lld\n", ans);
  }
  return (0 - 0);
}
