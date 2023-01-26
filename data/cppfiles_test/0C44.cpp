#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> v;
  for (int i = 0; i < n; ++i) {
    string s, temp1 = "", temp2 = "";
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (j % 2 == 0)
        continue;
      else {
        int ind = s[j] - 'A';
        s[j] = char((26 - ind) + 'A');
      }
    }
    v.push_back({s, i + 1});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    cout << v[i].second << ' ';
  }
}
