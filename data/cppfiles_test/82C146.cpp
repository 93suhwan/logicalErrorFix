#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
char s[N];
int a[N];
int t, n, m;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n >> m >> s + 1;
    for (int i = 1; i <= n; i++) {
      a[i] = a[i - 1] + ((s[i] == '+') ^ (i % 2 == 1) ? 1 : -1);
    }
    while (m--) {
      int l, r;
      cin >> l >> r;
      if (a[r] - a[l - 1] == 0)
        cout << 0 << endl;
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
          cout << 2 << endl << l - 1 << " " << long long << endl;
        } else
          cout << 1 << endl << long long << endl;
      }
    }
  }
}
