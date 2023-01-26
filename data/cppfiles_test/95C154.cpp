#include <bits/stdc++.h>
using namespace std;
void solve(int s, int n) {
  if (n == 1) {
    cout << s << endl;
    return;
  }
  int p = 1;
  while (p * 10 <= s) p *= 10;
  while (s - p < n - 1) p /= 10;
  cout << p << " ";
  solve(s - p, n - 1);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int s, n;
    cin >> s >> n;
    solve(s, n);
  }
  return 0;
}
