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
    res += ((n % 10) + '0');
    n /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
void solve() {
  long long x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  long long mn = min(p1, p2);
  ;
  p1 -= mn;
  p2 -= mn;
  if (p1 >= 7) {
    cout << ">";
    return;
  }
  if (p2 >= 7) {
    cout << "<";
    return;
  }
  for (int i = 0; i < p1; ++i) x1 *= 10;
  for (int i = 0; i < p2; ++i) x2 *= 10;
  if (x1 < x2)
    cout << "<";
  else if (x1 > x2)
    cout << ">";
  else
    cout << "=";
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
