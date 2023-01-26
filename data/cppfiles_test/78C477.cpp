#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
void solve() {
  long long a, b;
  cin >> a >> b;
  long long k = (b / 2) + 1;
  if (k < a) {
    cout << b % a << "\n";
  } else {
    cout << b % k << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
