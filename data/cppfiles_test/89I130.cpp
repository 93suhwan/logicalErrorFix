#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n;
long long a[N], b[N];
void solve() {
  int f = 1;
  for (int i = 1; i <= min(11, n); i++) {
    if (b[i] % a[i + 1] == 0) f = 0;
  }
  if (f)
    cout << "YES";
  else
    cout << "NO";
}
void read_file() {
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int f;
  a[0] = 1;
  int i;
  for (i = 1; a[i - 1] * i <= 1e9; i++) {
    a[i] = 1ll * a[i - 1] * i;
  }
  a[i] = a[i - 1] * i;
  for (cin >> t; t--; cout << endl) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    solve();
  }
}
