#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int n;
int c[200005];
int a[200005];
int b[200005];
int len;
void update(int x) {
  for (int i = x; i <= n; i += (i & -i)) c[i]++;
}
int query(int x) {
  int ans = 0;
  for (int i = x; i; i -= (i & -i)) ans += c[i];
  return ans;
}
int F(int x) { return lower_bound(b + 1, b + 1 + len, x) - b; }
void solve() {
  memset(c, 0, sizeof(c));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  len = unique(b + 1, b + 1 + n) - b - 1;
  deque<int> q;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (q.empty()) {
      q.push_back(F(a[i]));
      update(F(a[i]));
      continue;
    }
    int mi = query(F(a[i]) - 1);
    int self = query(F(a[i])) - query(F(a[i]) - 1);
    int mx = i - 1 - self - mi;
    if (mi < mx)
      q.push_front(a[i]), ans += mi;
    else
      q.push_back(a[i]), ans += mx;
    update(F(a[i]));
  }
  printf("%lld\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
