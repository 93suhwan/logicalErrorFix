#include <bits/stdc++.h>
using namespace std;
long long MAX = 1e9 + 7;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
long long powM(long long x, long long y, long long m) {
  long long ans = 1, r = 1;
  x = x % m;
  while (r > 0 && r <= y) {
    if (r & y) {
      ans = ans * x;
      ans = ans % m;
    }
    r = r << 1;
    x = x * x;
    x = x % m;
  }
  ans = ans % m;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long T = 0; T < t; T++) {
    long long n;
    cin >> n;
    long long b[n];
    for (long long i = 0; i < n; i++) cin >> b[i];
    long long a[n];
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      sum += b[i];
    }
    bool imp = 0;
    if ((sum) % (n * (n + 1) / 2) == 0)
      sum = (2 * sum) / (n * (n + 1));
    else {
      imp = 1;
    }
    if (!imp) {
      for (long long i = 0; i < n; i++) {
        if ((b[(i - 1 + n) % n] - b[i % n] + sum) % n == 0)
          a[i] = (b[(i - 1 + n) % n] - b[i % n] + sum) / n;
        else {
          imp = 1;
          break;
        }
        if (a[i] < 1 || a[i] > 1000000000) {
          imp = 1;
          break;
        }
      }
    }
    if (imp) {
      cout << "NO" << endl;
      goto done;
    } else {
      cout << "YES" << endl;
    }
    for (long long i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  done:;
  }
  return (0);
}
