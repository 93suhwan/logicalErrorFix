#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    char a[n + 2][n + 2], two = 0;
    memset(a, '0', sizeof a);
    vector<long long int> v;
    string s;
    cin >> s;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '2') {
        two++;
        v.push_back(i);
      }
    }
    if (two <= 2 && two) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (long long int i = 0; i < n; i++) {
        if (s[i] == '1') {
          for (long long int j = 0; j < n; j++) {
            a[i][j] = '=';
            a[j][i] = '=';
          }
        }
      }
      for (long long int i = 0; i < v.size(); i++) {
        for (long long int j = 0; j < v.size(); j++) {
          if (i == j) {
            continue;
          }
          if (a[v[i]][v[j]] == '0') {
            a[v[i]][v[j]] = '=';
          }
        }
        if (i == v.size() - 1) {
          a[v[i]][v[0]] = '+';
          a[v[0]][v[i]] = '-';
        } else {
          a[v[i]][v[i + 1]] = '+';
          a[v[i + 1]][v[i]] = '-';
        }
      }
      for (long long int i = 0; i < n; i++) {
        a[i][i] = 'X';
        for (long long int j = 0; j < n; j++) {
          cout << a[i][j];
        }
        cout << endl;
      }
    }
  }
  return 0;
}
