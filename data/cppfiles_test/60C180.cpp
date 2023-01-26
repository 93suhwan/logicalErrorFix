#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long t;
  long long ans = 0x7fffffff;
  for (int i = 0; i < n; i++) {
    cin >> t;
    ans &= t;
  }
  cout << ans;
  putchar('\n');
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
