#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    vector<int> va;
    vector<int> vb;
    int a, b, c, d;
    int ta = 0, tb = 0;
    cin >> a >> c >> b >> d;
    int aa = a, bb = b;
    while (a) {
      va.push_back(a % 10);
      a /= 10;
      ta++;
    }
    reverse(va.begin(), va.end());
    while (b) {
      vb.push_back(b % 10);
      b /= 10;
      tb++;
    }
    int h = min(va.size(), vb.size());
    reverse(vb.begin(), vb.end());
    ta += c;
    tb += d;
    if (ta > tb) {
      cout << ">" << endl;
      continue;
    } else if (tb > ta) {
      cout << "<" << endl;
      continue;
    } else {
      int f = 0;
      for (int i = 0; i < h; i++) {
        if (va[i] > vb[i]) {
          f = 1;
          break;
        } else if (vb[i] > va[i]) {
          f = 2;
          break;
        }
      }
      if (f == 0) {
        if (va.size() >= vb.size()) {
          for (int i = h; i < va.size(); i++) {
            if (va[i] > 0) {
              f = 1;
              break;
            }
          }
        } else {
          for (int i = h; i < vb.size(); i++) {
            if (vb[i] > 0) {
              f = 2;
              break;
            }
          }
        }
        if (f == 0) {
          cout << "=" << endl;
          continue;
        }
      }
      if (f == 1)
        cout << ">" << endl;
      else if (f == 2)
        cout << "<" << endl;
    }
  }
}
