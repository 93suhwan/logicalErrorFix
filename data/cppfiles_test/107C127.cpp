#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int num[100001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t, n, a, b;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    if (abs(a - b) > 1 || a + b > n - 2) {
      cout << -1 << endl;
      continue;
    }
    if (a > b)
      for (int i = 1; i <= n; i++) {
        num[i] = n - i + 1;
      }
    else if (a < b) {
      for (int i = 1; i <= n; i++) {
        num[i] = i;
      }
    } else {
      for (int i = 1; i <= n; i++) {
        num[i] = i;
      }
      for (int i = 1; i <= a; i++) swap(num[i * 2], num[i * 2 + 1]);
      for (int i = 1; i <= n; i++) cout << num[i] << ' ';
      cout << endl;
      continue;
    }
    int cnt = max(a, b);
    for (int i = 1; i <= cnt; i++) {
      swap(num[i * 2 - 1], num[i * 2]);
    }
    for (int i = 1; i <= n; i++) cout << num[i] << " ";
    cout << endl;
  }
  return 0;
}
