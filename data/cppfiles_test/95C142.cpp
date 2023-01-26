#include <bits/stdc++.h>
using namespace std;
void solve() {
  int s, n;
  cin >> s >> n;
  int p = pow(10, int(log10(s)));
  while (n > 1) {
    while ((s - p) < (n - 1)) {
      p /= 10;
    }
    cout << p << " ";
    s -= p;
    n--;
    p = pow(10, int(log10(s)));
  }
  cout << s << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
