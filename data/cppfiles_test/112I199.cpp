#include <bits/stdc++.h>
using namespace std;
void init() {}
int main() {
  init();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tests;
  cin >> tests;
  while (tests--) {
    long long int a, b, c, m;
    cin >> a >> b >> c >> m;
    if (a > 1 && m > 0) {
      a--;
      long long int mn = min(a, m);
      m -= mn;
      a -= mn;
    }
    if (b > 1 && m > 0) {
      b--;
      long long int mn = min(b, m);
      m -= mn;
      b -= mn;
    }
    if (c > 1 && m > 0) {
      c--;
      long long int mn = min(c, m);
      m -= mn;
      c -= mn;
    }
    vector<long long int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    long long int s = v[1] + v[0];
    if (m > 0)
      cout << "NO\n";
    else if (s >= v[2] - 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
