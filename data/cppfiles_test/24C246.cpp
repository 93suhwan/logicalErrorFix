#include <bits/stdc++.h>
using namespace std;
int const mod = 1e9 + 7;
void test_case() {
  int n;
  cin >> n;
  int ans = (n - 9) / 10;
  if (n < 9) ans = -1;
  cout << ans + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) test_case();
}
