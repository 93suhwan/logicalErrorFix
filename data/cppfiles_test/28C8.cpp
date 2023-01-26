#include <bits/stdc++.h>
using namespace std;
bool mindiv(int N) {
  if (N == 1) return false;
  if (N == 2) return true;
  for (int i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      return true;
    }
  }
  return false;
}
void solve() {
  long long int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  if (a + 2 * b == 3 * c) {
    cout << 0 << '\n';
    return;
  } else {
    long long int C = 0, B = 0, A = 0;
    if (c % 2 != 0) {
      C = c % 2;
    }
    if (b % 2 != 0) {
      B = b % 2;
    }
    if (a % 2 != 0) {
      A = a % 2;
    }
    cout << (C * 3 + B * 2 + A) % 2 << '\n';
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
