#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> bk(n);
    for (int i = 0; i < n; i++) {
      bk[i].second = i + 1;
      cin >> bk[i].first;
    }
    for (int j = 0; j < m; j++) {
      if (((j + 1) & 1) == 0) {
        for (int i = 0; i < n; i++) {
          bk[i].first[j] = 200 - bk[i].first[j];
        }
      }
    }
    sort(bk.begin(), bk.end());
    for (int i = 0; i < n; i++) {
      cout << bk[i].second << " ";
    }
  }
  return 0;
}
