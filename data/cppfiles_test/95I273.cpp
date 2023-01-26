#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long s, n;
  cin >> s >> n;
  long long d = log10(s);
  long long p = pow(10, d);
  while (n > 1) {
    while ((s - p) < (n - 1)) {
      p /= 10;
    }
    cout << p << " ";
    s -= p;
    n--;
    p = pow(10, int(log10(s)));
    cout << "x" << p << "\n";
  }
  cout << s << "\n";
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) solve();
}
