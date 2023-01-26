#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) f |= (c == '-'), c = getchar();
  while (isdigit(c)) sum = (sum << 1) + (sum << 3) + (c ^ 48), c = getchar();
  return f ? -sum : sum;
}
const int N = 1000010;
int n, m, ans, a[N], cnt[N];
inline int solve() {
  n = read(), m = read();
  for (register int i = (1); i <= (n); i++) a[i] = a[i + n] = read();
  vector<int> ans;
  ans.clear();
  for (register int i = (1); i <= (n); i++) cnt[i] = n;
  for (register int i = (1); i <= (n << 1); i++)
    if (i - a[i] + 1 >= 1) cnt[i - a[i] + 1]--;
  for (register int i = (1); i <= (n); i++) {
    if ((m << 1) >= cnt[i]) ans.push_back(i - 1);
  }
  sort(ans.begin(), ans.end());
  printf("%d ", ans.size());
  for (auto i : ans) printf("%d ", i);
  printf("\n");
}
signed main() {
  cout.tie(0);
  for (register int T = (read()); T >= (1); T--) solve();
}
