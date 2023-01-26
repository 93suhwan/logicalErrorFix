#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    printf("%d ", ++cnt);
  }
  puts("");
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
