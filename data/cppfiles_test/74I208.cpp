#include <bits/stdc++.h>
using namespace std;
int n, a, b;
void solve() {
  int k = (a + b) / 2 - a;
  int l = (a + b + 1) / 2 + a;
  if ((b - a) % 2 == 0) {
    cout << (l - k) / 2 << endl;
    for (int i = k; i <= l; i += 2) cout << i << " ";
  } else {
    cout << l - k + 1 << endl;
    for (int i = k; i <= l; i++) cout << i << " ";
  }
}
int main() {
  for (cin >> n; n--; cout << endl) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    solve();
  }
}
