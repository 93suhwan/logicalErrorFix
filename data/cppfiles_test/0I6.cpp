#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > v1;
  string a1[n];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a1[i] = s;
    pair<int, int> p1;
    p1.first = 0;
    p1.second = i + 1;
    v1.push_back(p1);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i % 2 == 0) {
        v1[j].first += int(a1[j][i]) - 65;
      } else {
        v1[j].first += -(int(a1[j][i]) - 90);
      }
    }
  }
  sort(v1.begin(), v1.end());
  for (int i = 0; i < n; i++) {
    cout << v1[i].second << " ";
  }
  return 0;
}
