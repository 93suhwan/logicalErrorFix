#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> solve(int x, int y, int z) {
  vector<pair<int, int>> v = vector<pair<int, int>>{pair<int, int>(abs(x), x),
                                                    pair<int, int>(abs(y), y),
                                                    pair<int, int>(abs(z), z)};
  sort(v.begin(), v.end());
  if (v[2].first % v[0].first != 0) {
    int d = v[2].first / v[0].first, r = v[2].first % v[0].first;
    vector<pair<int, int>> m = vector<pair<int, int>>();
    m.push_back(
        pair<int, int>(v[0].second, d * v[1].first * v[0].second / v[0].first));
    m.push_back(pair<int, int>(v[1].second, r * v[1].second / v[1].first));
    m.push_back(
        pair<int, int>(v[2].second, -v[1].first * v[2].second / v[2].first));
    return m;
  }
  if (v[2].first % v[1].first != 0) {
    int d = v[2].first / v[1].first, r = v[2].first % v[1].first;
    vector<pair<int, int>> m = vector<pair<int, int>>();
    m.push_back(
        pair<int, int>(v[1].second, d * v[0].first * v[1].second / v[1].first));
    m.push_back(pair<int, int>(v[0].second, r * v[0].second / v[0].first));
    m.push_back(
        pair<int, int>(v[2].second, -v[0].first * v[2].second / v[2].first));
    return m;
  } else {
    vector<pair<int, int>> m = vector<pair<int, int>>();
    m.push_back(pair<int, int>(v[2].second, -2));
    m.push_back(pair<int, int>(v[1].second, v[2].second / v[1].second));
    m.push_back(pair<int, int>(v[0].second, v[2].second / v[0].second));
    return m;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, a, b, c;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2) {
      n -= 3;
      cin >> a >> b >> c;
      vector<pair<int, int>> m = solve(a, b, c);
      set<int> s = set<int>{0, 1, 2};
      for (int x : {a, b, c}) {
        for (int i : s) {
          if (m[i].first == x) {
            cout << m[i].second << ' ';
            s.erase(i);
            break;
          }
        }
      }
    }
    while (n) {
      n -= 2;
      cin >> a >> b;
      cout << -b << ' ' << a << ' ';
    }
    cout << '\n';
  }
  return 0;
}
