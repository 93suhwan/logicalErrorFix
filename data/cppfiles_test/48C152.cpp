#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
const int mod = 1e9 + 7;
int a[N], c[N];
int tr[N];
int lowbit(int first) { return first & -first; }
int sum(int first) {
  int res = 0;
  for (int i = first; i; i -= lowbit(i)) res += tr[i];
  return res;
}
void add(int first, int n) {
  for (int i = first; i <= n; i += lowbit(i)) tr[i]++;
}
void solve() {
  int n;
  cin >> n;
  memset(c, 0, (n + 2) * sizeof(int));
  memset(tr, 0, (n + 2) * sizeof(int));
  int maxx = 1;
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), c[a[i]]++, maxx = max(c[a[i]], maxx);
  if (maxx >= 2) {
    puts("YES");
    return;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += sum(n) - sum(a[i]);
    add(a[i], n);
  }
  if (res & 1)
    puts("NO");
  else
    puts("YES");
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
