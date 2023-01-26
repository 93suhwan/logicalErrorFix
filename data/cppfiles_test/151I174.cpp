#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long q;
  cin >> q;
  vector<long long> ret;
  vector<int> p(5e5 + 1, -1);
  function<int(int)> myFind = [&](int n) {
    if (p[n] == -1) {
      return n;
    }
    return p[n] = myFind(p[n]);
  };
  vector<tuple<int, int, int> > query;
  for (int i = 0; i < q; ++i) {
    long long op, x, y;
    cin >> op >> x >> y;
  }
  reverse((query).begin(), (query).end());
  map<int, int> m;
  for (auto [op, x, y] : query) {
    if (op == 1) {
      if (m.count(x)) {
        ret.push_back(m[x]);
      } else {
        ret.push_back(x);
      }
    } else {
      if (m.count(y)) {
        m[x] = m[y];
      } else {
        m[x] = y;
      }
    }
  }
  reverse((ret).begin(), (ret).end());
  for (auto e : ret) {
    cout << e << ' ';
  }
  cout << '\n';
}
