#include <bits/stdc++.h>
using namespace std;
const long long maxi = 1000001;
const long long inf = 1e16;
const long long ninf = 1e16 * (-1);
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long ret = (power(a, b / 2)) % 1000000007;
  if (b % 2 == 0) return (ret * ret) % 1000000007;
  return ((ret * ret) % 1000000007 * a) % 1000000007;
}
long long power1(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long ret = (power(a, b / 2));
  if (b % 2 == 0) return (ret * ret);
  return ((ret * ret) * a);
}
long long modInverse(long long n) { return power(n, 1000000007 - 2); }
long long vis[maxi] = {0};
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long b[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = abs(a[i]);
    }
    vector<long long> v;
    long long z;
    if (n % 2 == 0) {
      for (long long i = 0; i < n; i += 2) {
        z = (b[i] * b[i + 1]) / gcd(b[i], b[i + 1]);
        if ((a[i] > 0 && a[i + 1] < 0) || a[i] < 0 && a[i + 1] > 0) {
          v.push_back(z / b[i]);
          v.push_back(z / b[i + 1]);
        } else {
          v.push_back(z / b[i]);
          v.push_back(0 - (z / b[i + 1]));
        }
      }
    } else {
      for (long long i = 0; i < n - 3; i += 2) {
        z = (b[i] * b[i + 1]) / gcd(b[i], b[i + 1]);
        if ((a[i] > 0 && a[i + 1] < 0) || a[i] < 0 && a[i + 1] > 0) {
          v.push_back(z / b[i]);
          v.push_back(z / b[i + 1]);
        } else {
          v.push_back(z / b[i]);
          v.push_back(0 - (z / b[i + 1]));
        }
      }
      long long ansh = a[n - 3] + a[n - 2];
      z = (b[n - 1] * ansh) / gcd(ansh, b[n - 1]);
      if (ansh == 0 && a[n - 3] > 0) {
        v.push_back(b[n - 1]);
        v.push_back(0 - b[n - 1]);
        if (a[n - 1] > 0)
          v.push_back(0 - (b[n - 3] + b[n - 2]));
        else
          v.push_back((b[n - 3] + b[n - 2]));
      } else if (ansh == 0 && a[n - 3] < 0) {
        v.push_back(0 - b[n - 1]);
        v.push_back(b[n - 1]);
        if (a[n - 1] > 0)
          v.push_back(0 - (b[n - 3] + b[n - 2]));
        else
          v.push_back((b[n - 3] + b[n - 2]));
      } else if ((ansh > 0 && a[n - 1] < 0) || (ansh < 0 && a[n - 1] > 0)) {
        v.push_back(z / ansh);
        v.push_back(z / ansh);
        v.push_back(z / b[n - 1]);
      } else {
        v.push_back(0 - (z / ansh));
        v.push_back(0 - (z / ansh));
        v.push_back(z / b[n - 1]);
      }
    }
    for (long long i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
