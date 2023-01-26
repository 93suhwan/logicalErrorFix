#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
  int b, f = 1;
  for (int i = 1; i <= n; i++) {
    cin >> b;
    int k = 0;
    while (b % (i + 1 - k) == 0 && k <= i - 1) k++;
    if (k == i) f = 0;
  }
  cout << (f ? "YES" : "NO");
}
void read_file() {
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (cin >> t; t--; cout << endl) {
    cin >> n;
    solve();
  }
}
