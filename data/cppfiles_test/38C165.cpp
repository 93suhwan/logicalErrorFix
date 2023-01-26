#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, ans = 0;
  cin >> n;
  if (n <= 6) {
    ans = 15;
  } else {
    if (n % 2 != 0) n++;
    ans = (n * 5) / 2;
  }
  cout << ans << '\n';
}
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
