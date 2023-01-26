#include <bits/stdc++.h>
using namespace std;
const long long int mx = 1e3 + 1, Mod = 1e9 + 7;
int n, k;
int ec[mx][mx];
void print(const vector<pair<int, int> > &a) {
  for (pair<int, int> p : a)
    cout << "(" << p.first << ", " << p.second << ")  ";
  cout << '\n';
}
void color(const vector<pair<int, int> > &b, int c) {
  for (int i = 0; i < b.size(); i++)
    for (int j = i + 1; j < b.size(); j++)
      for (int ii = b[i].first; ii < b[i].second; ii++)
        for (int jj = b[j].first; jj < b[j].second; jj++) ec[ii][jj] = c;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  vector<pair<int, int> > a, b;
  for (int i = 0; i < n; i++) a.push_back(make_pair(i, i + 1));
  int c = 0, m;
  while (a.size() > 1) {
    color(a, ++c);
    b.clear();
    m = a.size();
    int tmp = 0;
    for (int i = 0; i < m; i++) {
      if (i % k == k - 1 || i == m - 1) {
        b.push_back(make_pair(tmp, a[i].second));
        tmp = a[i].second;
      }
    }
    swap(a, b);
  }
  cout << c << '\n';
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) cout << ec[i][j] << ' ';
  return 0;
}
