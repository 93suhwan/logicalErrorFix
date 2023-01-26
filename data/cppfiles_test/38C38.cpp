#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n = 0;
  cin >> n;
  if (n <= 6) {
    cout << 15 << endl;
  } else {
    if (n % 2 == 1) {
      n++;
      cout << (n / 2) * 5 << endl;
    } else
      cout << (n / 2) * 5 << endl;
  }
}
int main() {
  int tst = 0;
  cin >> tst;
  while (tst--) {
    solve();
  }
  return 0;
}
