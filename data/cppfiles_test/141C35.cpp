#include <bits/stdc++.h>
using namespace std;
long long a, s, mahdi, t;
vector<long long> v;
int main() {
  cin >> t;
  t++;
  while (--t) {
    cin >> a >> s;
    vector<long long> v;
    while (s > 0) {
      long long x = a % 10;
      long long y = s % 10;
      mahdi = 0;
      if (x <= y) {
        v.push_back(y - x);
      } else {
        s /= 10;
        y += 10 * (s % 10);
        if (x < y && y >= 10 && y <= 19) {
          v.push_back(y - x);
        } else {
          mahdi = 1;
          break;
        }
      }
      a /= 10;
      s /= 10;
    }
    if (a > 0 || mahdi == 1) {
      cout << -1 << endl;
    } else {
      while (v.back() == 0) {
        v.pop_back();
      }
      for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
      }
      cout << endl;
      v.clear();
    }
  }
}
