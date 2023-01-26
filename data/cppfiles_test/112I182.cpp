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
    vector<long long int> v(3);
    for (long long int i = 0; i < 3; i++) cin >> v[i];
    long long int m;
    cin >> m;
    sort(v.begin(), v.end(), greater<long long int>());
    long long int d = v[0] - v[1];
    if (m > 0 && d > 1) {
      d--;
      long long int mn = min(m, d);
      m -= mn;
      v[0] -= mn;
    }
    if (m > 0 && v[2] > 1) {
      v[2]--;
      long long int mn = min(m, v[2]);
      v[2] -= mn;
      m -= mn;
    }
    if (m > 0) {
      long long int op1 = m / 2 + m % 2, op2 = m - op1;
      if (v[0] > 1) {
        v[0]--;
        long long int mn = min(v[0], op1);
        v[0] -= mn;
        m -= mn;
      }
      if (v[1] > 1 && m > 0) {
        v[1]--;
        long long int mn = min(op2, v[1]);
        v[1] -= mn;
        m -= mn;
      }
    }
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
