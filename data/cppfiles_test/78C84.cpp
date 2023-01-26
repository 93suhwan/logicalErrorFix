#include <bits/stdc++.h>
using namespace std;
int t;
bitset<30> p[200100];
int ct[30];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void finds(int x) {
  for (int i = 1; i <= x; i++) {
    if (x % i == 0) cout << i << ' ';
  }
  cout << '\n';
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    memset(ct, 0, sizeof(ct));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      p[i] = a;
    }
    for (int i = 0; i <= 29; i++) {
      for (int j = 1; j <= n; j++) {
        ct[i] += p[j][i];
      }
    }
    int ans = 0;
    for (int i = 0; i <= 29; i++) {
      ans = gcd(ans, ct[i]);
    }
    if (ans == 1)
      cout << ans << '\n';
    else if (ans == 0) {
      for (int i = 1; i <= n; i++) {
        cout << i << ' ';
      }
    } else
      finds(ans);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
}
