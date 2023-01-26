#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e6 + 5;
constexpr int MOD = 1e9 + 7;
int n, m, nl, nr, last;
int a[N];
bool dfs(int l, int r, int now) {
  if (a[l] > a[r]) {
    if ((nl - l + 1) & 1) return now == 1;
    return dfs(l, r - 1, now ^ 1);
  } else if (a[l] == a[r]) {
    int x = (nl - l + 1) & 1;
    int y = (nr - (n - r)) & 1;
    return (now == 1 && (x || y)) || (now == 0 && !(x || y));
  } else {
    if ((nr - (n - r)) & 1) return now == 1;
    return dfs(l + 1, r, now ^ 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  nl = 1, nr = 1;
  for (int i = 1; i < n; ++i)
    if (a[i] < a[i + 1])
      ++nl;
    else
      break;
  for (int i = n; i > 1; --i)
    if (a[i] < a[i - 1])
      ++nr;
    else
      break;
  puts(dfs(1, n, 1) ? "Alice" : "Bob");
}
