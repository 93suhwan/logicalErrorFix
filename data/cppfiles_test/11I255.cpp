#include <bits/stdc++.h>
using namespace std;
long long int mod1 = 1e9 + 7;
long long int mod2 = 998244353;
long long int inf = 1e9;
long long int maxxy = 1e6;
long double eps = 1e-9;
const double PI = 3.141592653589793238;
long long int power(long long int x, long long int y, long long int pp) {
  long long int res = 1;
  x = x % pp;
  while (y > 0) {
    if (y & 1) res = (res * x) % pp;
    y = y >> 1;
    x = (x * x) % pp;
  }
  return res;
}
long long int modInverse(long long int n, long long int pp) {
  return power(n, pp - 2, pp);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int z = (int)'z';
    long long int a = (int)'a';
    vector<map<char, long long int> > m(n);
    for (long long int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (long long int k = a; k <= z; k++) m[i][(char)k] = -s.size();
      for (long long int j = 0; j < s.size(); j++) {
        m[i][s[j]] += 2;
      }
    }
    long long int ans = 0;
    for (long long int it = a; it <= z; it++) {
      char z = (char)it;
      vector<long long int> v;
      for (long long int i = 0; i < n; i++) {
        v.push_back(m[i][z]);
      }
      sort(v.begin(), v.end());
      long long int cur = 0;
      long long int sum = 0;
      for (long long int i = n - 1; i >= 0; i--) {
        sum += v[i];
        if (sum > 0) {
          cur++;
        } else {
          break;
        }
      }
      ans = max(ans, cur);
      v.clear();
    }
    cout << ans << "\n";
  }
  return 0;
}
