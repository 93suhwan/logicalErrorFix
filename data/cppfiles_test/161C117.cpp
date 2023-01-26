#include <bits/stdc++.h>
using namespace std;
void func(int l, int r, set<int> *a, set<int> *b) {
  a[l].erase(r);
  b[r].erase(l);
  if (l == r) {
    cout << l << " " << r << " " << l << endl;
  } else if (a[l].size() == 0) {
    cout << l << " " << r << " " << l << endl;
    func(l + 1, r, a, b);
  } else if (b[r].size() == 0) {
    cout << l << " " << r << " " << r << endl;
    func(l, r - 1, a, b);
  } else {
    int maxa = *(--a[l].end()), minb = *(b[r].begin());
    if (minb == maxa + 2) {
      cout << l << " " << r << " " << maxa + 1 << endl;
      func(l, maxa, a, b);
      func(minb, r, a, b);
    }
  }
  return;
}
int main() {
  int t, n, m, l, r;
  cin >> t;
  while (t--) {
    cin >> n;
    set<int> a[1000 + 1], b[1000 + 1];
    m = n;
    while (m--) {
      cin >> l >> r;
      a[l].insert(r);
      b[r].insert(l);
    }
    func(1, n, a, b);
    cout << endl;
  }
  return 0;
}
