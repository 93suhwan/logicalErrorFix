#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -f;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
inline void chkmin(int &a, int b) {
  if (a > b) a = b;
}
inline void chkmax(int &a, int b) {
  if (a < b) a = b;
}
const int N = 2e6 + 5;
int t[N << 2];
int a[N], n, m, sum[N];
char str[N];
vector<vector<int>> out(N);
vector<vector<char>> s(N);
void build(int l, int r, int rt) {
  if (l == r) {
    t[rt] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  t[rt] = max(t[rt << 1], t[rt << 1 | 1]);
}
int query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) return t[rt];
  int mid = (l + r) >> 1;
  int ans = 0;
  if (L <= mid) ans = max(ans, query(L, R, l, mid, rt << 1));
  if (R > mid) ans = max(ans, query(L, R, mid + 1, r, rt << 1 | 1));
  return ans;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", str + 1);
    s[i].push_back('a');
    out[i].push_back(0);
    for (int j = 1; j <= m; j++) s[i].push_back(str[j]), out[i].push_back(0);
  }
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= m; j++)
      if (s[i][j - 1] == 'X' && s[i - 1][j] == 'X') a[j] = 1;
  for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + a[i];
  int q = read();
  while (q--) {
    int l = read(), r = read();
    if (sum[r] - sum[l])
      puts("NO");
    else
      puts("YES");
  }
}
