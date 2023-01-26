#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    b = b / 2;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0) {
    return a + b;
  }
  return gcd(b, a % b);
}
int32_t main() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long MX = 1 << 10;
  vector<long long> ans(MX, -1);
  ans[0] = 0;
  long long tmp;
  long long count = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < MX; j++) {
      if (ans[j] != -1 && v[i] > ans[j]) {
        tmp = j ^ v[i];
        if (ans[tmp] == -1) {
          ans[tmp] = v[i];
          count++;
        } else {
          ans[tmp] = min(ans[tmp], v[i]);
        }
      }
    }
    if (ans[v[i]] == -1) {
      count++;
      ans[v[i]] = v[i];
    } else {
      ans[v[i]] = min(ans[v[i]], v[i]);
    }
  }
  count++;
  cout << count << '\n';
  for (long long i = 0; i < MX; i++) {
    if (ans[i] != -1) {
      cout << i << " ";
    }
  }
  cout << '\n';
}
