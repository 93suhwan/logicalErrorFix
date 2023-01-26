#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 10;
long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  }
  return (x * power(x, n - 1)) % 1000000007;
}
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
int count_digits(int n) { return floor(log10(n) + 1); }
void ashu() {
  long long x, y;
  cin >> x >> y;
  long long ans;
  if (x > y) {
    ans = x + y;
  } else {
    long long temp = (x + y + 1) / 2;
    temp %= x;
    y -= temp;
    ans = y;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    ashu();
  }
}
