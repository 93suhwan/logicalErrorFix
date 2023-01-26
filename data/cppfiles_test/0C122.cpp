#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
vector<pair<string, int> > v;
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < (n + 1); i++) {
    string second;
    cin >> second;
    for (int j = 1; j < m; j += 2) {
      second[j] = 'Z' - (second[j] - 'A');
    }
    v.push_back(make_pair(second, i));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < (v.size()); i++) cout << v[i].second << " ";
}
int main() {
  solve();
  return 0;
}
