#include <bits/stdc++.h>
using namespace std;
int SquareCube(long long int N) {
  int cnt = 0, i = 1;
  while (int(pow(i, 6)) <= N) {
    ++cnt;
    ++i;
  }
  return cnt;
}
void solve() {
  long long n, ans = 0;
  cin >> n;
  ans = (long long)sqrt(n) + (long long)cbrt(n) - SquareCube(n);
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
