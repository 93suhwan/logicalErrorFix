#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, a, sum = 0, res = 0;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> a;
      sum += a;
      arr[i] = a;
    }
    double k = sum * 1.0 / n;
    if (floor(k * 2) != k * 2) {
      cout << 0 << '\n';
      continue;
    }
    long long k1 = floor(k * 2);
    map<long long, long long> m;
    for (long long i = 0; i < n; i++) {
      m[arr[i]]++;
    }
    for (long long i = 0; i < n; i++) {
      res += m[k1 - arr[i]];
      if (k1 - arr[i] == arr[i]) res -= 1;
    }
    cout << res / 2 << '\n';
  }
}
