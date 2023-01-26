#include <bits/stdc++.h>
using namespace std;
vector<int> P[2][26];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ((void)0);
  ((void)0);
  ((void)0);
  int T;
  string a, b;
  for (cin >> T; T--;) {
    bool ans = true;
    int p = -1;
    cin >> a >> b;
    if (a.size() < b.size()) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 26; j++) P[i][j].clear();
    for (int i = 0; i < a.size(); i++) P[i & 1][a[i] - 'a'].push_back(i);
    for (int i = 0; i < b.size(); i++) {
      p = upper_bound(P[i & 1][b[i] - 'a'].begin(), P[i & 1][b[i] - 'a'].end(),
                      p) -
          P[i & 1][b[i] - 'a'].begin();
      if (p == P[i & 1][b[i] - 'a'].size()) {
        ans = false;
        break;
      }
      p = P[i & 1][b[i] - 'a'][p];
    }
    if (ans) {
      cout << "YES\n";
      continue;
    }
    p = -1;
    ans = true;
    for (int i = 0; i < b.size(); i++) {
      p = upper_bound(P[~i & 1][b[i] - 'a'].begin(),
                      P[~i & 1][b[i] - 'a'].end(), p) -
          P[~i & 1][b[i] - 'a'].begin();
      if (p == P[~i & 1][b[i] - 'a'].size()) {
        ans = false;
        break;
      }
      p = P[~i & 1][b[i] - 'a'][p];
    }
    cout << (ans ? "YES\n" : "NO\n");
  }
  return 0;
}
