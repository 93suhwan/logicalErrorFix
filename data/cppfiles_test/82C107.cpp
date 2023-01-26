#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
char s[N];
int a[N];
int t, n, m;
int sum[N];
void solve() {
  cin >> n >> m >> s + 1;
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + ((s[i] == '+') ^ (i % 2 == 1) ? 1 : -1);
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    if (a[r] - a[l - 1] == 0)
      cout << 0 << '\n';
    else {
      int long long = l, rr = r, ok = 0;
      if ((r - l + 1) % 2 == 0) ok = 1, l++, long long ++;
      if (a[r] - a[l] == 0)
        long long = rr = l;
      else if (a[r - 1] - a[l - 1] == 0)
        long long = rr = r;
      else
        while (long long != rr) {
          int mid = long long + rr >> 1;
          if ((a[mid - 1] - a[l - 1] == a[r] - a[mid]) ||
              (a[mid - 1] - a[l - 1] > a[r] - a[mid]) == (-a[r] + a[l] < 0))
            rr = mid;
          else
            long long = mid + 1;
        }
      if (ok) {
        cout << 2 << '\n' << l - 1 << " " << long long << '\n';
      } else
        cout << 1 << '\n' << long long << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  cin >> t;
  while (t--) solve();
}
