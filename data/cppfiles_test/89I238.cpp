#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = int(1e9), mod = 1e9 + 7, base = 1;
long long n, m, a[N], q, used[N];
string s;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      used[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] % (i + 1)) {
        used[i] = used[i - 1] + 1;
      } else {
        used[i] = used[i - 1];
      }
    }
    bool cond = 0;
    for (int i = n; i >= 1; i--) {
      if (a[i] % (i + 1) == 0) {
        if (used[i]) {
          used[i]--;
        } else {
          cond = 1;
        }
      }
    }
    if (cond) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
