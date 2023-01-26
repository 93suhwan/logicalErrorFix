#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
int readint() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
int a[1005];
unordered_map<int, vector<int> > hv;
bool can[1005];
void dfs1(int u, int rem, vector<int> &now, int sum) {
  if (!rem) {
    if (hv.count(sum)) {
      vector<int> ans(0);
      vector<int> tmp = hv[sum];
      int lst = 0;
      for (int i = 0; i < now.size(); i++) {
        ans.push_back(a[now[i]] - lst);
        lst = a[now[i]] - lst;
        ans.push_back(a[tmp[i]] - lst);
        lst = a[tmp[i]] - lst;
        can[now[i]] = can[tmp[i]] = 1;
      }
      for (int i = 1; i <= n; i++) {
        if (can[i]) continue;
        ans.push_back(a[i]);
      }
      printf("YES\n");
      for (auto r : ans) printf("%d ", r);
      printf("\n");
      exit(0);
    }
    hv[sum] = now;
    return;
  }
  for (int i = u; i <= n - rem + 1; i++) {
    now.push_back(i);
    dfs1(i + 1, rem - 1, now, sum + a[i]);
    now.pop_back();
  }
}
void work(int k) {
  if (k >= 10) assert(n <= 30);
  vector<int> now(0);
  hv.clear();
  dfs1(1, k, now, 0);
}
int main() {
  n = readint();
  for (int i = 1; i <= n; i++) a[i] = readint();
  sort(a + 1, a + n + 1);
  m = unique(a + 1, a + n + 1) - a - 1;
  if (m < n) {
    printf("YES\n");
    printf("0 ");
    for (int i = 1; i <= m; i++) printf("%d ", a[i]);
    for (int i = m + 2; i <= n; i++) printf("0 ");
    printf("\n");
    return 0;
  }
  if (n == 3) {
    if ((a[1] + a[2] + a[3]) % 2 == 0) {
      printf("YES\n");
      int tmp = (a[1] + a[2] + a[3]) / 2;
      printf("%d %d %d\n", tmp - a[1], tmp - a[2], tmp - a[3]);
    } else
      printf("NO\n");
    return 0;
  }
  int pl = 0;
  for (int i = 1; i <= n; i++)
    if (!(a[i] & 1)) pl = i;
  if (pl) {
    vector<int> ans(0);
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (i == pl || j == pl) continue;
        if ((a[i] + a[j] + a[pl]) % 2 == 0) {
          int tmp = (a[i] + a[j] + a[pl]) / 2;
          ans.push_back(tmp - a[i]);
          ans.push_back(tmp - a[j]);
          ans.push_back(tmp - a[pl]);
          int t1 = tmp - a[i];
          for (int k = 1; k <= n; k++)
            if (k != i && k != j && k != pl) ans.push_back(a[k] - t1);
          printf("YES\n");
          for (auto r : ans) printf("%d ", r);
          printf("\n");
          return 0;
        }
      }
    }
  }
  for (int i = 1; i <= n / 2; i++) work(i);
  printf("NO\n");
  return 0;
}
