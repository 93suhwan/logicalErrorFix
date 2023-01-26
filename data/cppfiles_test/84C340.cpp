#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, s;
  cin >> n >> s;
  if (n == 1) {
    cout << s << endl;
    return;
  }
  int p = n / 2 + 1;
  int median = s / p;
  while (median * p > s) median--;
  cout << median << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
