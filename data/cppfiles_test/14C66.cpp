#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 0x3f3f3f3f;
const long long modn = 1e9;
const long long N = 2e5 + 5;
long long a[55];
long long b[55];
map<long long, long long> m;
struct node {
  long long l, r, d;
} no[55];
void solve() {
  m.clear();
  long long n;
  long long num = 0;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    m[a[i]] = i;
  }
  sort(b + 1, b + 1 + n);
  for (long long i = n; i >= 2; i--) {
    if (a[i - 1] > a[i]) {
      long long l = i - 1;
      long long j = i - 1;
      for (; j <= n; j++) {
        if (a[j] > a[i - 1]) break;
      }
      long long r = j - 1;
      sort(a + l, a + 1 + r);
      no[num].l = l;
      no[num].r = r;
      no[num].d = 1;
      num++;
    }
  }
  cout << num << '\n';
  for (long long i = 0; i < num; i++) {
    cout << no[i].l << " " << no[i].r << " " << no[i].d << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
