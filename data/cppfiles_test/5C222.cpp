#include <bits/stdc++.h>
const int dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};
const int x_dir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int y_dir[] = {-1, 0, 1, -1, 1, -1, 0, 1};
using namespace std;
int solve() {
  int n;
  cin >> n;
  string s1;
  string s2;
  cin >> s1;
  cin >> s2;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] == '0' && s2[i] == '1') {
      c++;
      s1[i] = '2';
      s2[i] = '2';
    }
  }
  for (int i = 0; i < n; i++) {
    if (s2[i] == '1') {
      if (i - 1 >= 0 && s1[i - 1] == '1') {
        s1[i - 1] = 2;
        c++;
      } else if (i + 1 < n && s1[i + 1] == '1') {
        s1[i + 1] = '2';
        c++;
      }
    }
  }
  cout << c << endl;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
