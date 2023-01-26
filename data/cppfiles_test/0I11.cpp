#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
vector<pair<string, int> > v;
bool cmp(pair<string, int> x, pair<string, int> y) {
  bool oke = true;
  string fi = x.first, se = y.first;
  for (int i = 0; i < (fi.size()); i++) {
    if (i % 2 == 0) {
      if (fi[i] > se[i]) oke = false;
    } else if (fi[i] < se[i])
      oke = false;
  }
  return oke;
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < (n + 1); i++) {
    string tmp;
    cin >> tmp;
    v.push_back(make_pair(tmp, i));
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < (v.size()); i++) cout << v[i].second << " ";
}
int main() {
  solve();
  return 0;
}
