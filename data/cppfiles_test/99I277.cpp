#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void tc() {
  cin >> n >> s;
  vector<int> cycle;
  vector<string> res(n, string(n, '-'));
  for (int i = 0; i < n; i++) {
    res[i][i] = 'X';
    if (s[i] == '1') {
      for (int j = 0; j < n; j++) {
        if (j == i) continue;
        res[i][j] = res[j][i] = '=';
      }
    } else {
      cycle.push_back(i);
    }
  }
  if (cycle.size() == 1 || cycle.size() == 2) {
    cout << "NO" << endl;
    return;
  }
  for (size_t i = 0; i < cycle.size(); i++) {
    int p1 = cycle[i];
    int p2 = cycle[(i + 1) % cycle.size()];
    res[p1][p2] = '+';
  }
  cout << "YES" << endl;
  for (string &line : res) cout << line << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    tc();
  }
  return 0;
}
