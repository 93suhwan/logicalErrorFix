#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a, b;
  cin >> n >> m;
  vector<pair<int, int> > v;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    v.push_back(make_pair(a, b));
  }
  int q;
  cin >> q;
  while (q--) {
    int p;
    cin >> p;
    if (p == 1) {
      cin >> a >> b;
      if (a > b) swap(a, b);
      v.push_back(make_pair(a, b));
    } else if (p == 2) {
      cin >> a >> b;
      if (a > b) swap(a, b);
      for (int i = 0; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;
        if (x == a && y == b) {
          v.erase(v.begin() + i);
          break;
        }
      }
    } else {
      sort(v.begin(), v.end());
      int s = n, k = 1, o = v.size();
      for (int i = 0; i < o - 1; i++) {
        int x = v[i].first;
        int y = v[i + 1].first;
        if (x != y) k++;
      }
      int z = n - k;
      cout << z << "\n";
    }
  }
  return 0;
}
