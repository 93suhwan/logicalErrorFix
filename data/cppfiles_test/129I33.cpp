#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int inf = 1e9;
const long long mod = 1e9 + 7;
const int N = 1e6 + 8;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == i + 1) continue;
      if (a[i] >= 2 * n) {
        cnt++;
      } else if (a[i] < i + 1 || a[i] <= 2 * n) {
        cnt = -1;
        break;
      }
    }
    if (cnt == -1) {
      cout << cnt << '\n';
    } else {
      cout << cnt - cnt1 << '\n';
    }
  }
  return 0;
}
