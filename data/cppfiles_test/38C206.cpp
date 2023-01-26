#include <bits/stdc++.h>
using namespace std;
void IOS() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int maxn = 1e5 + 5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n < 6) {
      cout << "15" << '\n';
      continue;
    }
    long long ans = 0;
    if (n % 2 == 1) n++;
    int p = n % 10;
    if (p == 2) {
      ans = (n - 12) * 5 / 2 + 2 * 15;
    } else if (p == 4) {
      ans = (n - 24) * 5 / 2 + 3 * 20;
    } else if (p == 6) {
      ans = (n - 6) * 5 / 2 + 15;
    } else if (p == 8) {
      ans = (n - 8) * 5 / 2 + 20;
    } else
      ans = n * 5 / 2;
    cout << ans << '\n';
  }
  return 0;
}
