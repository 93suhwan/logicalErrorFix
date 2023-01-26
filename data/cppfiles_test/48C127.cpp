#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int c[N];
int tree[N];
int lowbit(int x) { return x & -x; }
int sum(int x) {
  int res = 0;
  for (int i = x; i; i -= lowbit(i)) res += tree[i];
  return res;
}
void add(int x, int n) {
  for (int i = x; i <= n; i += lowbit(i)) tree[i]++;
}
void solve() {
  int n;
  cin >> n;
  memset(c, 0, (n + 2) * sizeof(int));
  memset(tree, 0, (n + 2) * sizeof(int));
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    c[a[i]]++;
    maxx = max(maxx, c[a[i]]);
  }
  if (maxx > 1) {
    cout << "YES" << endl;
    return;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += sum(n) - sum(a[i]);
    ;
    add(a[i], n);
  }
  if (res & 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
