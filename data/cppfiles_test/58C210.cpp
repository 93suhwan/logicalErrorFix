#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long m;
    cin >> m;
    vector<vector<long long>> res(2, vector<long long>(m));
    string str1, str2;
    cin >> str1 >> str2;
    for (long long i = 0; i < m; i++) {
      res[0][i] = str1[i] - '0';
    }
    for (long long i = 0; i < m; i++) {
      res[1][i] = str2[i] - '0';
    }
    long long flag = 0;
    for (long long i = 0; i < m; i++) {
      if (res[0][i] == 1 && res[1][i] == 1) {
        cout << "NO" << endl;
        flag = 1;
        break;
      }
    }
    if (flag == 0) cout << "YES" << endl;
  }
  return 0;
}
