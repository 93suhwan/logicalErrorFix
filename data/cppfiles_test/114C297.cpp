#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const long long INF = 1e18;
const double eps = 1e-8;
int T;
int n, a[N];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  for (cin >> T; T--;) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int cnt = n / 2, p = 2;
    while (cnt--) {
      cout << a[p++] << ' ' << a[1] << '\n';
    }
  }
  return 0;
}
