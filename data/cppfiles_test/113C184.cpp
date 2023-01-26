#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x1, x2, p1, p2, t, d1 = 0, d2 = 0;
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  t = x1;
  vector<int> v1, v2;
  while (t > 0) {
    d1++;
    v1.push_back(t % 10);
    t /= 10;
  }
  t = x2;
  while (t > 0) {
    d2++;
    v2.push_back(t % 10);
    t /= 10;
  }
  if (d1 + p1 > d2 + p2)
    cout << ">" << endl;
  else if (d1 + p1 < d2 + p2)
    cout << "<" << endl;
  else {
    long long i = d1 - 1, j = d2 - 1;
    for (; i >= 0 && j >= 0; i--, j--) {
      if (v1[i] > v2[j]) {
        cout << ">" << endl;
        return;
      } else if (v1[i] < v2[j]) {
        cout << "<" << endl;
        return;
      }
    }
    if (i >= 0) {
      while (i >= 0) {
        if (v1[i] > 0) {
          cout << ">" << endl;
          return;
        }
        i--;
      }
    } else if (j >= 0) {
      while (j >= 0) {
        if (v2[j] > 0) {
          cout << "<" << endl;
          return;
        }
        j--;
      }
    }
    cout << "=" << endl;
  }
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
