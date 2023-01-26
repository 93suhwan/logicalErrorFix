#include <bits/stdc++.h>
using namespace std;
long long modvalue(long long x) {
  return (x % 1000000007 + 1000000007) % 1000000007;
}
long long power(long long x, long long n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return power(x * x, n / 2);
  else
    return x * power(x * x, (n - 1) / 2);
}
long long my_own() {
  long long m, q, n, i, j = 0, mx = INT_MIN, mn = INT_MAX, k, count = 0, x = 0,
                        ans = INT_MAX, sum = 0, y = 0, ch = 0;
  string s1, s2;
  cin >> s1 >> s2;
  map<char, long long> m1;
  for (i = 0; i < 26; i++) m1[s1[i]] = i;
  n = s2.size();
  long long def = m1[s2[0]];
  for (i = 0; i < n; i++) {
    sum += abs(m1[s2[i]] - def);
    def = m1[s2[i]];
  }
  cout << sum << endl;
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) my_own();
  return 0;
}
