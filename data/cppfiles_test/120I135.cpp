#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = ((res % p) * (x % p)) % p;
    y = y >> 1;
    x = ((x % p) * (x % p)) % p;
  }
  return res % p;
}
long long int lop(long long int n) {
  long long int cnt = -1;
  while (n != 0) {
    n /= 2;
    cnt++;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    long long int power = lop(r);
    long long int ans1 = r - pow(2, power) + 1;
    long long int ans2 = pow(2, power) - pow(2, power - 1);
    long long int MAXIMUM = max(ans1 * 1LL, ans2 * 1LL);
    long long int ans3 =
        ((r - l + 1) % 2) ? ((r - l + 1) / 2 + 1) : ((r - l + 1) / 2);
    MAXIMUM = max(MAXIMUM, ans3 * 1LL);
    cout << (r - l + 1) - MAXIMUM << endl;
  }
  return 0;
}
