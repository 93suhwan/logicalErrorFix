#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
const int M = 1000000007;
int n;
void read() { cin >> n; }
void solve() { printf("%d 1 1\n", n - 2); }
signed main() {
  int t = 1;
  cin >> t;
  while (t--) {
    read();
    solve();
  }
  return 0;
}
