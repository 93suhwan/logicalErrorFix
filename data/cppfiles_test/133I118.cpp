#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 10;
vector<long long> v1, v2, v3;
set<int> set1, set2, set3;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return (y, x % y);
}
pair<int, int> paa;
int ex(int x) { return x = x * x; }
bool ispoweroftwo(int n) { return n && (!(n & (n - 1))); }
bool isNumber(const string& str) {
  return str.find_first_not_of("0123456789") == string::npos;
}
int fac(int j) {
  if (j == 1 || j == 0)
    return 1;
  else
    return j * fac(j - 1);
}
long long t, x1, p1, x2, p2, ans, n, ans1, ans2, ok, a[10], x, b, c, d, e, f;
string s, s1, s2, s3, s4, su;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  s3 = "a";
  char sd[110][2];
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 1, ok = 0, ans1 = 0, x = 0, b = 0, c = 0, s = "";
    for (int i = 0; i < n - 2; i++) {
      cin >> sd[i][0] >> sd[i][1];
    }
    for (int i = 0; i < n - 3; i++) {
      s += sd[i][0];
    }
    cout << s << sd[n - 3][0] << sd[n - 3][1] << s3 << '\n';
  }
}
