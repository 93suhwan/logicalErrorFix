#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double PI = atan2(0, -1);
void solve() {
  long long n;
  cin >> n;
  long long count_one = 0, count_zero = 0;
  for (int i = 0; i < n; ++i) {
    long long temp;
    cin >> temp;
    if (temp == 1) {
      count_one++;
    } else if (temp == 0) {
      count_zero++;
    }
  }
  long long ans = count_one * (1LL << count_zero);
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) {
    solve();
    cout << "\n";
  }
  return 0;
}
