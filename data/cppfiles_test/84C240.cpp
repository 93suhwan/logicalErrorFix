#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const long long mod = 998244353;
pair<int, int> p[2010];
void solve() {
  int a, b;
  cin >> a >> b;
  if (a % 2 == 1)
    cout << 2 * b / (a + 1) << endl;
  else
    cout << 2 * b / (a + 2) << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
