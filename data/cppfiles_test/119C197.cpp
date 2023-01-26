#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;
void solve() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    sum += x;
  }
  if (sum % n == 0) {
    cout << 0 << '\n';
  } else {
    cout << 1 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
