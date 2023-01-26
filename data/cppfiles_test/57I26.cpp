#include <bits/stdc++.h>
using namespace std;
void print(bool flag) {
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
void solve() {
  long long s, n, k;
  cin >> s >> n >> k;
  long long t = 0;
  if (n % k == 0)
    t = 2 * n;
  else
    t = (n / k) * k * 2 + n % k;
  print(s < t);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
