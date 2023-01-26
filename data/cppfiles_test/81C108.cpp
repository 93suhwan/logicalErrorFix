#include <bits/stdc++.h>
using namespace std;
class Fenwick {
 public:
  vector<int> t;
  int n;
  void init(int nn) {
    n = nn;
    t.assign(n, 0);
  }
  int sum(int r) {
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r];
    return result;
  }
  void inc(int i, int delta) {
    for (; i < n; i = (i | (i + 1))) t[i] += delta;
  }
  int sum(int l, int r) { return sum(r) - sum(l - 1); }
  void init(vector<int> &a) {
    init((int)a.size());
    for (int i = 0; i < a.size(); i++) inc(i, a[i]);
  }
};
int main() {
  int tst;
  cin >> tst;
  for (int t = 0; t < tst; ++t) {
    int n, q;
    cin >> n >> q;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      if (c == '+') {
        if (i % 2 == 0) {
          arr.push_back(1);
        } else {
          arr.push_back(-1);
        }
      } else {
        if (i % 2 == 1) {
          arr.push_back(1);
        } else {
          arr.push_back(-1);
        }
      }
    }
    Fenwick fw;
    fw.init(arr);
    for (int i = 0; i < q; ++i) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      int sm = fw.sum(l, r);
      if (sm == 0) {
        cout << 0 << endl;
      } else if ((r - l + 1) % 2 == 1) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
  return 0;
}
