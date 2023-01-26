#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.001;
const int N = 200010;
void solve() {
  long long n;
  cin >> n;
  if (n == 0) {
    cout << "-1 1\n";
    return;
  }
  if (n == 1) {
    cout << "0 1\n";
    return;
  }
  if (n > 0) {
    cout << "-" << n - 1 << " " << n << endl;
    return;
  }
  if (n < 0) {
    cout << n << " " << abs(n) - 1 << endl;
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}
