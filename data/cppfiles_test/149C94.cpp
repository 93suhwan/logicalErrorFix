#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long INF = 1e18;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long nCr(long long n, long long r) {
  long long res = 1;
  if (n < r) return -1;
  r = min(r, n - r);
  for (long long i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long nPr(long long n, long long r) {
  long long res = 1;
  if (n < r) return -1;
  for (long long i = 0; i < r; i++) res *= (n - i);
  return res;
}
long long modexp(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    y = y >> 1;
  }
  return res;
}
bool isOverflow(long long a, long long b) {
  if (a == 0 || b == 0) return false;
  long long result = a * b;
  if (a == result / b)
    return false;
  else
    return true;
}
void solve() {
  long long n, k, x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long c = 0;
    while (i < n && s[i] == '*') i++, c++;
    if (c > 0) v.push_back(c), i--;
  }
  if (v.size() == 0) {
    cout << s << "\n";
    return;
  }
  long long curp = 0;
  for (long long i = 0; i < v.size(); i++) {
    v[i] = 1 + v[i] * k;
  }
  long long id = v.size() - 1;
  long long flag = 0;
  while (curp < x) {
    if ((double)v[id] > (double)INF / curp) {
      flag = 1;
      id--;
      break;
    }
    if (curp == 0)
      curp = v[id];
    else
      curp = curp * v[id];
    id--;
  }
  id++;
  if (flag == 0) curp = curp / v[id];
  vector<long long> b(v.size(), 0);
  long long y = x;
  for (long long i = id; i < v.size(); i++) {
    if (i == v.size() - 1) {
      b[i] = y;
      break;
    }
    b[i] = (y - 1) / (curp);
    y = y % curp;
    if (y == 0) y = curp;
    if (i + 1 < v.size()) curp = curp / v[i + 1];
  }
  b[b.size() - 1]--;
  string ans = "";
  long long ind = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'a')
      ans.push_back('a');
    else {
      for (long long j = 0; j < b[ind]; j++) ans.push_back('b');
      ind++;
      while (i < n && s[i] == '*') i++;
      i--;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
