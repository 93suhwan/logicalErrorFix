#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) return false;
  for (long long i = 2; i < sqrt(n) + 1; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long seive(long long n) {
  vector<bool> marked(n + 1, false);
  marked[1] = true;
  for (long long i = 2; i <= sqrt(n); i++) {
    for (long long j = i * i; j <= n; j += i) marked[j] = true;
  }
  long long count = 0;
  for (long long i = 2; i <= n; i++)
    if (!marked[i]) count++;
  return count;
}
long long totient(long long n) {
  long long result = n;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void subString(string s, long long n, vector<pair<string, long long>>& a) {
  for (long long i = 0; i < s.size(); i++)
    for (long long len = 1; len <= s.size() - i; len++) {
      string l = s.substr(i, len);
      a.push_back(make_pair(l, l.size()));
    }
}
void substring(string s, string k) {
  if (s.size() == 0) {
    cout << k << " ";
    return;
  }
  string op1 = k;
  string op2 = k;
  op2.push_back(s[0]);
  s.erase(s.begin() + 0);
  substring(s, op1);
  substring(s, op2);
  return;
}
void solve() {
  long double W, H, x1, x2, y1, y2, w, h;
  cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
  long double l1 = abs(x2 - x1);
  long double h1 = abs(y1 - y2);
  long double ans = INT_MAX, fl = 0;
  if (h <= y1 || y2 + h <= H || x2 + w <= W || w <= x1) {
    ans = 0;
    cout << setprecision(10) << fixed << ans << "\n";
    return;
  }
  if (l1 + w <= W) ans = min(ans, min(W - x2, x1)), fl++;
  if (h <= H - h1) ans = min(ans, min(y1, H - y2)), fl++;
  if (!fl)
    cout << "-1\n";
  else
    cout << setprecision(10) << fixed << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1, el = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
