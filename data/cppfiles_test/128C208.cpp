#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n - 3 << " 2 1" << endl;
  } else {
    n--;
    n /= 2;
    if (n % 2 == 0) {
      cout << n + 1 << " " << n - 1 << " 1\n";
    } else {
      cout << n + 2 << " " << n - 2 << " 1\n";
    }
  }
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
