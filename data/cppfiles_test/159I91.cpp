#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
  if (n == 1) {
    cout << 1 << endl;
    cout << 1 << endl;
  } else if (n == 2) {
    cout << 1 << endl;
    cout << 1 << endl;
  } else if (n % 2 == 0) {
    if (n / 2 % 2 == 1)
      cout << n - 2 << endl;
    else
      cout << n - 1 << endl;
    for (int i = 1; i <= n; i++) {
      if (n / 2 % 2 == 1 && i == 2) continue;
      if (n / 2 == i) continue;
      cout << i << " ";
    }
    cout << endl;
  } else {
    solve(n - 1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  solve(n);
  return 0;
}
