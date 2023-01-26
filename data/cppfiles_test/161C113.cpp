#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0, c = getchar();
  bool f = 0;
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 1;
  for (; isdigit(c); c = getchar()) x = x * 10 + (c & 15);
  return f ? -x : x;
}
constexpr int N = 1005;
int n;
vector<int> a[N];
void solve(int l, int k) {
  if (a[l][k] == l) {
    printf("%d %d %d\n", l, l, l);
    return;
  }
  if (k == a[l].size() - 1) {
    printf("%d %d %d\n", l, a[l][k], l);
    solve(l + 1, 0);
    return;
  }
  if (a[l][k + 1] == a[l][k] - 1) {
    printf("%d %d %d\n", l, a[l][k], a[l][k]);
    solve(l, k + 1);
    return;
  }
  printf("%d %d %d\n", l, a[l][k], a[l][k + 1] + 1);
  solve(l, k + 1);
  solve(a[l][k + 1] + 2, 0);
}
void work() {
  n = gi();
  for (int i = 1; i <= n; ++i) {
    a[i].clear();
  }
  for (int i = 1; i <= n; ++i) {
    int l = gi(), r = gi();
    a[l].push_back(r);
  }
  for (int i = 1; i <= n; ++i) {
    sort(a[i].begin(), a[i].end());
    reverse(a[i].begin(), a[i].end());
  }
  solve(1, 0);
  puts("");
}
int main() {
  int T = gi();
  while (T--) {
    work();
  }
  return 0;
}
