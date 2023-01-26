#include <bits/stdc++.h>
using namespace std;
bool compare(pair<long long, long long> x, pair<long long, long long> y) {
  if (x.first == y.first)
    return x.second > y.second;
  else
    return x.first < y.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long a, b, c, m;
    cin >> a >> b >> c >> m;
    long long x = a + b + c - 3;
    if (m > x) {
      cout << "NO\n";
    } else {
      long long y = max(a, max(b, c)) - (a + b + c - max(a, max(b, c)));
      y--;
      if (y < 0) y = 0;
      if (m >= y) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
