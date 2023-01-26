#include <bits/stdc++.h>
const int mod = 1000000007;
using namespace std;
int gcd(int a, int b) {
  if (a > b) {
    return gcd(b, a);
  }
  if (a == 0) return b;
  return gcd(b % a, a);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
long long Pow(long long a, long long b) {
  if (b == 0) {
    return (long long)1;
  }
  if (b % 2 == 0) {
    return Pow(a, b / 2) * Pow(a, b / 2);
  } else {
    return a * Pow(a, b - 1);
  }
}
void solve() {
  long long x, n;
  cin >> x >> n;
  if (n == 0) {
    cout << x << '\n';
    return;
  }
  if (x % 2 == 0) {
    x--;
    n--;
    long long q = n / 4;
    x += (q * (-4));
    long long cur = (q * 4) + 1;
    long long rem = n % 4;
    if (rem == 1) {
      cur++;
      x += cur;
    } else if (rem == 2) {
      cur++;
      x += cur;
      cur++;
      x += cur;
    } else if (rem == 3) {
      cur++;
      x += cur;
      cur++;
      x += cur;
      cur++;
      x -= cur;
    }
    cout << x << '\n';
  } else {
    x++;
    n--;
    long long q = n / 4;
    x += (q * (4));
    long long cur = (q * 4) + 1;
    long long rem = n % 4;
    if (rem == 1) {
      cur++;
      x -= cur;
    } else if (rem == 2) {
      cur++;
      x -= cur;
      cur++;
      x -= cur;
    } else if (rem == 3) {
      cur++;
      x -= cur;
      cur++;
      x -= cur;
      cur++;
      x += cur;
    }
    cout << x << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
