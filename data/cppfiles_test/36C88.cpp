#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 'a' << '\n';
    return;
  }
  if ((n - 1) % 2) {
    for (int i = 0; i < n / 2; i++) {
      cout << 'a';
    }
    cout << 'x';
    for (int i = 0; i < (n - 2) / 2; i++) {
      cout << 'a';
    }
    cout << '\n';
  } else {
    for (int i = 0; i < (n - 1) / 2; i++) {
      cout << 'a';
    }
    cout << 'x';
    for (int i = 0; i < (n - 3) / 2; i++) {
      cout << 'a';
    }
    cout << "y\n";
  }
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
