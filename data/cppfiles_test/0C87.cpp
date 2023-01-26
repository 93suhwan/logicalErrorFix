#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b;
  cin >> n >> b;
  vector<pair<string, int>> v;
  string a[n];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a[i] = s;
    v.push_back(make_pair(s, i));
  }
  for (int i = 0; i < n; i++) {
    string s3 = "";
    for (int j = 0; j < b; j++) {
      string s2 = "";
      if ((j + 1) % 2 == 0) {
        int c = 90 - int(a[i][j]);
        s2 += char(c + 65);
      } else {
        int c = int(a[i][j]);
        s2 += char(c);
      }
      s3 += s2;
    }
    v[i].first = s3;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i].second + 1 << " ";
  }
  return 0;
}
