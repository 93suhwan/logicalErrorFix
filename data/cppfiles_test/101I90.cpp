#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int u;
      cin >> u;
      a.push_back(u);
    }
    vector<int> b;
    vector<int> r;
    for (int i = 0; i < n; i++) {
      char ch;
      cin >> ch;
      if (ch == 'B') {
        b.push_back(a[i]);
      } else {
        r.push_back(a[i]);
      }
    }
    bool flg = true;
    sort(b.begin(), b.end());
    sort(r.begin(), r.end());
    int i = 0, j = 0, c = 1;
    while (i < b.size()) {
      if (b[i] < c) {
        flg = false;
        cout << "NO\n";
        break;
      }
      i++;
      c++;
    }
    while (j < r.size()) {
      if (r[j] > c) {
        flg = false;
        cout << "NO\n";
        break;
      }
      j++;
      c++;
    }
    if (flg) {
      cout << "YES\n";
    }
    a.clear();
    b.clear();
    r.clear();
  }
}
