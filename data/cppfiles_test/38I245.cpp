#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int p = (n / 6) * 15 + 15;
  if (n % 6 == 0) {
    p = (n / 6) * 15;
  }
  if (n % 8 == 0) {
    p = min(p, (n / 8) * 20);
  } else if (n % 8 <= 6) {
    p = min(p, (n / 8) * 20 + 15);
  } else {
    p = min(p, (n / 8) * 20 + 20);
  }
  if (n % 10 == 0) {
    p = min(p, (n / 10) * 25);
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
