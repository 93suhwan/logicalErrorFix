#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long temp = power(x, y / 2);
  if (y % 2 == 1)
    return temp * temp * x;
  else
    return temp * temp;
}
const int N = (int)1e5 + 9;
void solve() {
  long long n;
  cin >> n;
  cout << -(n - 1) << " " << n << "\n";
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
