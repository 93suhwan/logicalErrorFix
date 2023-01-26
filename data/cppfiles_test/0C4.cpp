#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<string, int> > v1;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    pair<string, int> p1;
    p1.first = s;
    p1.second = i + 1;
    v1.push_back(p1);
  }
  for (int i = 0; i < n; i++) {
    string s1 = "";
    for (int j = 0; j < m; j++) {
      string s2 = "";
      if (j % 2 == 0) {
        s2 += v1[i].first[j];
      } else {
        int x = 90 - int(v1[i].first[j]);
        s2 += char(65 + x);
      }
      s1 += s2;
    }
    v1[i].first = s1;
  }
  sort(v1.begin(), v1.end());
  for (int i = 0; i < n; i++) {
    cout << v1[i].second << " ";
  }
  return 0;
}
