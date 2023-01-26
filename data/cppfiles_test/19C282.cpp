#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x < 0) x *= -1;
      if (x == 0) ok = 1;
      v.push_back(x);
    }
    vector<pair<int, int> > E;
    for (int i = 1; i < (1 << n); i++) {
      int aux = 0, sum = 0;
      for (int l = 0; l < n; l++) {
        if ((1 << l) & i) {
          aux |= (1 << l);
          sum += v[l];
        }
      }
      E.push_back({aux, sum});
    }
    for (int i = 0; i < E.size(); i++) {
      for (int l = i + 1; l < E.size(); l++) {
        if ((E[i].first & E[l].first) == 0) {
          if (E[i].second == E[l].second) {
            ok = 1;
            break;
          }
        }
      }
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
