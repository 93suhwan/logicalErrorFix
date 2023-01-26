#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
void solve() {
  long long n;
  cin >> n;
  if (n % 3 == 0)
    cout << n / 3 << " " << n / 3 << "\n";
  else if ((n - 1) % 3 == 0)
    cout << (n - 1) / 3 + 1 << " " << (n - 1) / 3 << "\n";
  else
    cout << (n - 1) / 3 << " " << (n - 1) / 3 + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
