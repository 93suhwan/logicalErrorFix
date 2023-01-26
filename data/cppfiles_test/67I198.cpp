#include <bits/stdc++.h>
using namespace std;
void init() {}
long long binExpo(long long x, long long y) {
  long long res = 1;
  if (y == 0) return 1;
  if (y % 2 == 0)
    res = binExpo(x * x, y / 2) % (1000000007);
  else
    res = (binExpo(x * x, y / 2) * x) % (1000000007);
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
string upper(string s) {
  transform(s.begin(), s.end(), s.begin(), ::toupper);
  return s;
}
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long diff = abs(a - b);
  long long mx = max(a, b);
  long long mn = min(a, b);
  if (c > mn && c < mx)
    cout << diff + c << endl;
  else
    cout << -1 << endl;
}
int main() {
  init();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
