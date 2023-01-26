#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  long long ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<long long> x) {
  for (long long i = 0; i < (long long)x.size(); i++)
    printf("%lld%c", x[i], " \n"[i == (long long)x.size() - 1]);
}
long long a[4005], n, m;
long long val[4005], f[4005][4005], vis[4005];
signed main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) {
    f[i][i] = a[i];
    for (long long j = i + 1; j <= n; j++) f[i][j] = min(f[i][j - 1], a[j]);
  }
  long long ans = 0;
  for (long long i = 1; i <= m; i++) {
    long long maxn = -0x3f3f3f3f3f3f3f3f, maxid = 0;
    for (long long j = 1; j <= n; j++)
      if (!vis[j]) {
        long long w = val[j] * 2 + (m - 1) * a[j];
        if (w > maxn) maxn = w, maxid = j;
      }
    vis[maxid] = 1;
    ans += maxn;
    for (long long i = 1; i < maxid; i++) val[i] -= f[i][maxid];
    for (long long i = maxid + 1; i <= n; i++) val[i] -= f[maxid][i];
  }
  cout << ans << endl;
  return 0;
}
