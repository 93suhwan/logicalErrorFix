#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  if (y == 1) return x;
  return ((y & 1) ? (x * pow(x, y - 1)) : (pow(x * x, y / 2)));
}
long long pt(long long n) {
  long long cnt = -1;
  while (n != 0) {
    n /= 2;
    cnt++;
  }
  return cnt;
}
void solve() {
  long long l, r;
  cin >> l >> r;
  long long pw = pt(r);
  long long first = r - pow(2, pw) + 1;
  long long second = pow(2, pw) - pow(2, pw - 1);
  long long maxi = max(first * 1LL, second * 1LL);
  long long ans3 =
      ((r - l + 1) % 2) ? ((r - l + 1) / 2 + 1) : ((r - l + 1) / 2);
  maxi = max(maxi, ans3 * 1LL);
  cout << (r - l + 1) - maxi;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_case;
  cin >> test_case;
  for (int t = 1; t <= test_case; t++) {
    solve();
    cout << endl;
  }
  return 0;
}
