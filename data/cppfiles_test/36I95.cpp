#include <bits/stdc++.h>
using namespace std;
void solve(int tc) {
  int n;
  cin >> n;
  int odd = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum += x;
    if (x & 1) odd = i;
  }
  for (int i = 2; i * i <= sum; ++i) {
    if (sum % i == 0) {
      cout << n << '\n';
      for (int i = 0; i < n; ++i) {
        cout << i + 1 << ' ';
      }
      cout << '\n';
      return;
    }
  }
  cout << n - 1 << '\n';
  for (int i = 0; i < n; ++i) {
    if (i == odd) continue;
    cout << i << ' ';
  }
  cout << '\n';
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t = 0, T = 1;
  cin >> T;
  while (t < T) solve(++t);
  return 0;
}
