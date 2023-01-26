#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f;
const double eps = 1e-6;
int a[N];
inline int get(int x, int y) { return x / abs(x) * abs(y); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n & 1) {
      for (int i = 1; i <= n - 3; i += 2) {
        cout << get(a[i], a[i + 1]) << ' ' << -get(a[i + 1], a[i]) << ' ';
      }
      cout << get(a[n - 2], a[n]) << ' ' << get(a[n - 1], a[n]) << ' '
           << -get(a[n], ((abs(a[n - 1]) + abs(a[n - 2]))));
    } else {
      for (int i = 1; i <= n; i += 2) {
        cout << get(a[i], a[i + 1]) << ' ' << -get(a[i + 1], a[i]) << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}
