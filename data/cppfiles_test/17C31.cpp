#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;
int ans;
int tr[N];
int lowbit(int x) { return x & -x; }
int sum(int x) {
  int res = 0;
  for (int i = x; i; i -= lowbit(i)) res += tr[i];
  return res;
}
void init() {
  for (int i = 0; i <= n; i++) tr[i] = 0;
}
void add(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}
void solve() {
  scanf("%d", &n);
  init();
  vector<int> a, b;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for (auto &it : a) it = lower_bound(b.begin(), b.end(), it) - b.begin() + 1;
  add(a[0], 1);
  long long ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    int c = sum(a[i] - 1);
    int d = sum(n) - sum(a[i]);
    ans += min(c, d);
    add(a[i], 1);
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
