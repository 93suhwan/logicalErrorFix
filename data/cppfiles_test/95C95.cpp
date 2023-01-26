#include <bits/stdc++.h>
using namespace std;
int digit(int n) {
  int val = 1;
  while (n > 9) {
    val *= 10;
    n /= 10;
  }
  return val;
}
void solve(int s, int n) {
  if (n == 1) {
    cout << s << endl;
  } else if (s - digit(s) >= n - 1) {
    cout << digit(s) << " ";
    solve(s - digit(s), n - 1);
  } else if (s - digit(s) / 10 >= n - 1) {
    cout << digit(s) / 10 << " ";
    solve(s - digit(s) / 10, n - 1);
  } else {
    cout << digit(s) / 100 << " ";
    solve(s - digit(s) / 100, n - 1);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int s, n;
    cin >> s >> n;
    solve(s, n);
  }
  return 0;
}
