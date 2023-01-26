#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a, b;
  cin >> a >> b;
  vector<pair<string, int>> v;
  for (int i = 1; i <= a; i++) {
    string s;
    cin >> s;
    v.push_back({s, i});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < a; i++) {
    string t = v[i].first;
    int p = i;
    while (i + 1 < a) {
      i++;
      string q = v[i].first;
      if (t[0] != q[0]) {
        i--;
        break;
      }
    }
    for (int j = i; j >= p; j--) {
      cout << v[j].second << " ";
    }
  }
  return 0;
}
