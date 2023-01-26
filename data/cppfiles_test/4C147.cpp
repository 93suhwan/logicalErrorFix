#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
  int a = 2;
  int b = (n) / 2;
  if (n == 5) {
    cout << 2 << " " << 4 << "\n";
    return;
  } else if (n % a == n % b) {
    cout << a << " " << b << "\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
  }
  return 0;
}
