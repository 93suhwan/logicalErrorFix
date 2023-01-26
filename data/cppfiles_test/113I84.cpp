#include <bits/stdc++.h>
using namespace std;
long long Pow(long long n, long long k) {
  long long a = n;
  for (int i = 0; i < k; ++i) n *= a;
  return n;
}
string itos(long long n) {
  string res;
  while (n) {
    res += ((n % 10) - '0');
    n /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
void solve() {
  long long x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  p1 -= min(p1, p2);
  p2 -= min(p1, p2);
  string x = itos(x1), y = itos(x2);
  for (int i = 0; i < p1; ++i) {
    x += ('0');
  }
  for (int i = 0; i < p2; ++i) {
    y += ('0');
  }
  if (x == y) {
    cout << "=";
    return;
  }
  if (x.size() > y.size()) {
    cout << ">";
    return;
  }
  if (y.size() > x.size()) {
    cout << "<";
    return;
  }
  for (int i = 0; i < x.size(); ++i) {
    if (x[i] != y[i]) {
      if (x[i] > y[i]) {
        cout << ">";
        return;
      }
      cout << "<";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve(), cout << endl;
  return 0;
}
