#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
void sieve() {}
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long fexp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 1000000007;
    b /= 2;
    a = a * a % 1000000007;
  }
  return ans;
}
long long inverse(long long a, long long p) { return fexp(a, p - 2); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  long long t = 0;
  while (t++ < T) {
    long long n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<long long> pre(n, 0);
    if (s[0] == '+')
      pre[0] = 1;
    else
      pre[0] = -1;
    for (long long i = 1; i < n; i++) {
      long long x;
      if (s[i] == '+')
        x = 1;
      else
        x = -1;
      if (i % 2) x = -x;
      pre[i] = pre[i - 1] + x;
    }
    vector<vector<long long> > m(2 * n + 5);
    for (long long i = 0; i < n; i++) {
      m[pre[i] + n].push_back(i);
    }
    for (long long i = 0; i < q; i++) {
      long long l, r;
      long long val = 0;
      cin >> l >> r;
      l--;
      r--;
      long long sum;
      if (l == 0)
        sum = pre[r];
      else
        sum = pre[r] - pre[l - 1];
      if (sum == 0) {
        cout << 0 << endl;
        continue;
      }
      if ((r - l + 1) % 2) {
        cout << 1 << endl;
        if (l > 0) val += pre[l - 1];
        long long z = (abs(sum) + 1);
        z /= 2;
        if (sum < 0) z = -z;
        val += z;
        long long in = lower_bound(m[val + n].begin(), m[val + n].end(), l) -
                       m[val + n].begin();
        cout << m[val + n][in] + 1 << endl;
      } else {
        cout << 2 << endl;
        if (r - l > 1) {
          long long y = pre[r - 1];
          if (l > 0) y -= pre[l - 1];
          long long z = (abs(y) + 1);
          z /= 2;
          if (y < 0) z = -z;
          if (l > 0) val += pre[l - 1];
          val += z;
          long long in = lower_bound(m[val + n].begin(), m[val + n].end(), l) -
                         m[val + n].begin();
          cout << m[val + n][in] + 1 << " " << r + 1 << endl;
        }
        if (r - l == 1) {
          cout << l + 1 << " " << r + 1 << endl;
        }
      }
    }
  }
  return 0;
}
