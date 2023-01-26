#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
long long power(long long a, long long b) {
  if (b == 0) {
    return 1;
  } else if (b % 2 == 0) {
    return power((a * a), b >> 1);
  } else
    return (a * (power((a * a), b >> 1)));
}
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n % 2 == 0) {
      cout << "YES" << endl;
      continue;
    }
    vector<long long> v;
    long long c = 1;
    map<long long, long long> m;
    for (long long i = 0; i < n - 1; i++) {
      if (a[i] < a[i + 1]) {
        c++;
      } else {
        v.push_back(c);
        m[c]++;
        c = 1;
      }
    }
    { m[c]++; }
    bool w = 1;
    for (auto i = m.begin(); i != m.end(); i++) {
      if ((*i).first % 2 != 0) {
        if (n - (*i).first > 0) {
          cout << "YES" << endl;
          w = 0;
          break;
        }
      }
    }
    if (w == 1) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
