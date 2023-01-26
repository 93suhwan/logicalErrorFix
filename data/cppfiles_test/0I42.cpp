#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const long double pi = 2 * acos(0.0);
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
int x = 0, y = 1;
bool comp1(pair<string, int> a, pair<string, int> b) {
  return a.first[x] < b.first[x];
}
bool comp2(pair<string, int> a, pair<string, int> b) {
  return a.first[y] > b.first[y];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n, flag;
  cin >> n >> m;
  vector<pair<string, int>> v(n);
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    v[i].first = s;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end(), comp1);
  x += 2;
  for (int a = 0; a < n - 1; a++) {
    if (v[a].first[x - 2] == v[a + 1].first[x - 2]) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    for (int i = 1; i < m; i++) {
      flag = 0;
      int j = 0;
      if (i % 2 == 1) {
        for (int a = 0; a < n - 1;) {
          while (v[a].first[x - 2] == v[a + 1].first[x - 2]) {
            a++;
            if (a == n - 1) {
              break;
            }
          }
          a++;
          if (a - j > 1) sort(v.begin() + j, v.begin() + a, comp2);
          j = a;
        }
        y += 2;
        for (int a = 0; a < n - 1; a++) {
          if (v[a].first[y - 2] == v[a + 1].first[y - 2]) {
            flag = 1;
            break;
          }
        }
      } else {
        for (int a = 0; a < n - 1;) {
          while (v[a].first[y - 2] == v[a + 1].first[y - 2]) {
            a++;
            if (a == n - 1) {
              break;
            }
          }
          a++;
          if (a - j > 1) sort(v.begin() + j, v.begin() + a, comp1);
          j = a;
        }
        x += 2;
        for (int a = 0; a < n - 1; a++) {
          if (v[a].first[x - 2] == v[a + 1].first[x - 2]) {
            flag = 1;
            break;
          }
        }
      }
      if (flag == 0) break;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << v[i].second << " ";
  }
  cout << "\n";
  return 0;
}
