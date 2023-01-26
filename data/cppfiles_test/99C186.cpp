#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t, n;
  string s;
  vector<int> v2;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    cin >> s;
    v2.clear();
    for (int j = 0; j < n; ++j) {
      if (s[j] == '2') v2.push_back(j);
    }
    if (v2.size() <= 2 && v2.size() != 0)
      cout << "NO\n";
    else {
      int h = 0, h1;
      if (v2.size()) h1 = v2.back(), v2.push_back(v2[0]);
      cout << "YES\n";
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          if (k == j)
            cout << 'X';
          else {
            if (v2.size()) {
              if (v2[h] == j && v2[h + 1] == k)
                cout << '-';
              else if (v2[h] == j && h == 0 && h1 == k)
                cout << '+';
              else if (v2[h] == j && v2[h - 1] == k)
                cout << '+';
              else
                cout << '=';
            } else
              cout << '=';
          }
        }
        if (v2.size() && v2[h] == j) h++;
        cout << '\n';
      }
    }
  }
  return 0;
}
