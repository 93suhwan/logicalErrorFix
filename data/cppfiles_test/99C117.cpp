#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string types;
    cin >> types;
    vector<int> twos;
    for (int i = 0; i < n; i++)
      if (types[i] == '2') twos.push_back(i);
    if (twos.size() == 1 || twos.size() == 2) {
      cout << "NO" << endl;
      continue;
    }
    vector<vector<int> > match(n, vector<int>(n, 0));
    for (int i = 0; i < twos.size(); i++) {
      for (int j = 0; j < twos.size(); j++) {
        if (j == i + 1 || i == twos.size() - 1 && j == 0)
          match[twos[i]][twos[j]] = 1;
        if (j == i - 1 || i == 0 && j == twos.size() - 1)
          match[twos[i]][twos[j]] = -1;
      }
    }
    cout << "YES" << endl;
    vector<string> ans(n, "");
    int pnt = 0;
    for (int i = 0; i < n; i++) {
      if (types[i] == '1') {
        for (int j = 0; j < i; j++) ans[i] += '=';
        ans[i] += 'X';
        for (int j = i + 1; j < n; j++) ans[i] += '=';
      } else {
        pnt++;
        pnt %= n;
        for (int j = 0; j < n; j++) {
          if (j == i)
            ans[i] += 'X';
          else if (match[i][j] == 1)
            ans[i] += '+';
          else if (match[i][j] == -1)
            ans[i] += '-';
          else
            ans[i] += '=';
        }
      }
      cout << ans[i] << endl;
    }
  }
}
