#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<string, int> s[1010101];
string a, b;
bool cmp(pair<string, int> x, pair<string, int> y) {
  a = x.first;
  b = y.first;
  for (int i = 0; i < m; i++) {
    if (a[i] == b[i]) {
      continue;
    }
    if (i % 2 == 0) {
      if (a[i] < b[i]) {
        return true;
      }
      return false;
    } else {
      if (a[i] > b[i]) {
        return true;
      }
      return false;
    }
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i].first;
    s[i].second = i + 1;
  }
  sort(s, s + n, cmp);
  for (int i = 0; i < n; i++) {
    cout << s[i].second << ' ';
  }
  cout << endl;
  return 0;
}
