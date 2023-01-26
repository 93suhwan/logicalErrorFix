#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
const int N = 1e5 + 1;
const long long linf = (long long)(1e18 + 1);
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  cin >> test;
  while (test--) {
    int n, v;
    cin >> n;
    multiset<pair<int, int> > s;
    queue<pair<int, int> > a;
    for (int i = 0; i < n; i++) {
      cin >> v;
      if (v != 0) s.insert({v, i});
    }
    multiset<pair<int, int> >::iterator it1, it2;
    pair<int, int> x, y;
    while ((int)((s).size()) > 1) {
      it1 = s.begin();
      it2 = s.end();
      --it2;
      x = *it1;
      y = *it2;
      s.erase(it1);
      s.erase(it2);
      a.push({x.second, y.second});
      --x.first;
      --y.first;
      if (x.first > 0) s.insert(x);
      if (y.first > 0) s.insert(y);
    }
    cout << (int)((a).size()) << '\n';
    while (!a.empty()) {
      x = a.front();
      cout << x.first + 1 << " " << x.second + 1 << '\n';
      a.pop();
    }
  }
  return 0;
}
