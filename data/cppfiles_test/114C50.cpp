#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int f[N];
bool st[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  int n;
  cin >> t;
  while (t--) {
    cin >> n;
    memset(st, 0, sizeof st);
    for (int i = 0; i < n; i++) cin >> f[i], st[f[i]] = true;
    sort(f, f + n);
    int cnt = 0;
    int m = n / 2;
    for (int i = n - 1; i >= 0 && cnt < m; i--) {
      if (!st[f[i] % f[0]]) {
        cout << f[i] << ' ' << f[0] << endl;
        cnt++;
      }
    }
  }
  return 0;
}
