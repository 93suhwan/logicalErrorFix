#include <bits/stdc++.h>
using namespace std;
long long or_q(long long a, long long b) {
  cout << "or " << a << " " << b << endl;
  long long x;
  cin >> x;
  return x;
}
long long and_q(long long a, long long b) {
  cout << "and " << a << " " << b << endl;
  long long x;
  cin >> x;
  return x;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v;
    long long _12 = and_q(1, 2) + or_q(1, 2);
    long long _23 = and_q(2, 3) + or_q(2, 3);
    long long _31 = and_q(3, 1) + or_q(3, 1);
    long long sum = _12 + _23 + _31;
    sum >>= 1;
    v.push_back(sum - _23);
    v.push_back(sum - _12);
    v.push_back(sum - _31);
    for (long long i = 4; i <= n; i++) {
      long long temp = and_q(1, i) + or_q(1, i) - v[0];
      v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cout << "finish " << v[k - 1] << endl;
  }
  return 0;
}
