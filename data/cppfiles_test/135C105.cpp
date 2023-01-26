#include <bits/stdc++.h>
using namespace std;
vector<long long> sieve(long long n) {
  long long *arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long binpow(long long a, long long b, long long m) {
  a = a % m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
class cmp {
 public:
  bool operator()(pair<long long, long long> &a,
                  pair<long long, long long> &b) {
    if (a.second == b.second)
      return a.first < b.first;
    else
      return a.second < b.second;
  }
};
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    long long x = k;
    sort(v.begin(), v.end());
    long long ans = 0;
    k *= 2;
    long long j = n - 1;
    vector<long long> vec;
    while (k--) {
      vec.push_back(v[j]);
      j--;
    }
    sort(vec.begin(), vec.end());
    for (long long i = 0; i < vec.size() / 2; i++) {
      ans += (vec[i] / vec[i + x]);
    }
    for (long long i = 0; i <= j; i++) ans += v[i];
    cout << ans << "\n";
    ;
  }
}
