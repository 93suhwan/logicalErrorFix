#include <bits/stdc++.h>
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const long long INF64 = (long long)1e18;
const double INFD = 1e30;
const double EPS = 1e-9;
const double PI = std::acos(-1);
const int MOD = 1e9 + 7;
template <typename T>
inline T read() {
  T X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
const int MAXN = 300005;
const int MAXV = (1 << 17) + 5;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
int dr2[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc2[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int CASE = 1;
int A[MAXN];
int B[MAXN], vis[MAXN];
int cnt[MAXN];
int n, m;
void dfs(int x) {
  if (vis[x]) return;
  vis[x] = true;
  dfs(B[x]);
}
int countCC(int k) {
  for (int i = 0; i < n; i++) {
    B[i] = A[(i + k) % n];
    vis[i] = 0;
  }
  int cc = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
      cc++;
    }
  }
  return cc;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    A[i] = read<int>() - 1;
    cnt[(i - A[i] + n) % n]++;
  }
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (cnt[i] >= n - 2 * m) {
      if (n - countCC(i) <= m) {
        ans.push_back(i);
      }
    }
  }
  printf("%d ", ans.size());
  for (auto v : ans) {
    printf("%d ", v);
  }
  printf("\n");
}
int main() {
  int T = read<int>();
  while (T--) {
    solve();
  }
  return 0;
}
