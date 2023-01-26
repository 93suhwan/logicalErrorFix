#include <bits/stdc++.h>
using namespace std;
map<string, pair<int, int> > mymap;
int emuqreba(int a, int b, int c, int d) {
  if (a == c || b == d) return 1;
  if (abs(a - c) == abs(b - d)) return 1;
  return 0;
}
int solve() {
  vector<vector<pair<int, int> > > v(150);
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++) v[0].push_back(make_pair(i, j));
  string s;
  int x = -1, y = -1;
  int kx = -1, ky = -1;
  for (int k = 0;; k++) {
    int newx = -1;
    int newy = -1;
    while (true) {
      newx = rand() % 8 + 1;
      newy = rand() % 8 + 1;
      if (newx != x || newy != y)
        if (x == -1 || emuqreba(x, y, newx, newy)) break;
    }
    x = newx;
    y = newy;
    cout << x << " " << y << endl;
    cin >> s;
    pair<int, int> pa = mymap[s];
    if (s == "Done") return 0;
    for (int i = 0; i < v[k].size(); i++)
      if (v[k][i].first + pa.first >= 1 && v[k][i].first + pa.first <= 8)
        if (v[k][i].second + pa.second >= 1 && v[k][i].second + pa.second <= 8)
          if (!emuqreba(x, y, v[k][i].first + pa.first,
                        v[k][i].second + pa.second))
            v[k + 1].push_back(make_pair(v[k][i].first + pa.first,
                                         v[k][i].second + pa.second));
    if (v[k + 1].size() == 1) {
      kx = v[k + 1][0].first;
      ky = v[k + 1][0].second;
      break;
    }
  }
  cout << x << " " << ky << endl;
  cin >> s;
  if (s == "Done") return 0;
  pair<int, int> pa = mymap[s];
  kx += pa.first;
  ky += pa.second;
  if (pa.second == 1) {
    while (true) {
      cout << kx << " " << ky - 1 << endl;
      cin >> s;
      if (s == "Done") return 0;
      kx += mymap[s].first;
      ky += mymap[s].second;
    }
  } else {
    while (true) {
      cout << kx << " " << ky + 1 << endl;
      cin >> s;
      if (s == "Done") return 0;
      kx += mymap[s].first;
      ky += mymap[s].second;
    }
  }
  return 1;
}
int main() {
  mymap["Left"] = make_pair(-1, 0);
  mymap["Up-Left"] = make_pair(-1, -1);
  mymap["Down-Left"] = make_pair(-1, 1);
  mymap["Up"] = make_pair(0, -1);
  mymap["Up-Right"] = make_pair(1, -1);
  mymap["Right"] = make_pair(1, 0);
  mymap["Down-Right"] = make_pair(1, 1);
  mymap["Down"] = make_pair(0, 1);
  srand(time(0));
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
