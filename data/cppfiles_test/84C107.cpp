#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 6;
const int MOD = 0;
void solve() {
  int n;
  cin >> n;
  int s;
  cin >> s;
  n -= (n - 1) / 2;
  cout << s / n << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
