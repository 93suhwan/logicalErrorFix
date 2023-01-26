#include <bits/stdc++.h>
using namespace std;
void solve();
void quick() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
bool same(int a, int b) {
  if (a == b) return true;
  return false;
}
int main() {
  quick();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
void solve() {
  map<pair<int, int>, int> m;
  int n;
  cin >> n;
  vector<int> v(n), v1(n);
  for (int i = 0; i < (n); ++i) {
    pair<int, int> x;
    cin >> x.first >> x.second;
    v[i] = x.first;
    v1[i] = x.second;
    m[x] = 1;
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = v[i]; j <= v1[i]; j++) {
      if (v[i] == v1[i])
        cout << j << " " << j << " " << j << endl;
      else if (m[{v[i], j - 1}] == 1 && m[{j + 1, v1[i]}] == 1)
        cout << v[i] << " " << v1[i] << " " << j << endl;
      else if ((m[{j + 1, v1[i]}]) == 1 || m[{v[i], j - 1}] == 1)
        cout << v[i] << " " << v1[i] << " " << j << endl;
    }
  }
  cout << endl;
}
