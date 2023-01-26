#include <bits/stdc++.h>
using namespace std;
void die(string S) {
  puts(S.c_str());
  exit(0);
}
int bit[333][333];
int pos[100100];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > v;
    for (int i = 0; i < n * m; i++) {
      bit[i / m][i % m] = 0;
      int x;
      cin >> x;
      v.push_back(make_pair(x, -i));
    }
    sort((v).begin(), (v).end());
    int ans = 0;
    for (int i = 0; i < n; i++) pos[-v[i].second] = i;
    for (int i = 0; i < n; i++) {
      int x = pos[i] / m, y = pos[i] % m;
      for (int j = 0; j < y; j++) ans += bit[x][j];
      bit[x][y] = 1;
    }
    cout << ans << endl;
  }
  return 0;
}
