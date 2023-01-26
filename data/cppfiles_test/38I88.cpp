#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  int a = n % 6;
  int b = n % 8;
  int c = n % 10;
  if (a == 0) {
    cout << 15 * (n / 6) << endl;
    return;
  }
  if (b == 0) {
    cout << 20 * (n / 8) << endl;
    return;
  }
  if (c == 0) {
    cout << 25 * (n / 10) << endl;
    return;
  }
  long long int p = (n / 6) * 15 + 15;
  if (n % 8 <= 6) {
    p = min(p, (n / 8) * 20 + 15);
  } else {
    p = min(p, (n / 8) * 20 + 20);
  }
  if (n % 10 <= 6) {
    p = min(p, (n / 10) * 25 + 15);
  } else if (n % 10 <= 8) {
    p = min(p, (n / 10) * 25 + 20);
  } else {
    p = min(p, (n / 10) * 25 + 25);
  }
  cout << p << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
