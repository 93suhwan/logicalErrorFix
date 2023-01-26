#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<vector<long long int> > v(5, vector<long long int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 5; j++) cin >> v[j][i];
    bool flag = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 5; j++) {
        long long int a = 0, b = 0, cnt = 0;
        for (int k = 0; k < n; k++) {
          if (v[i][k] == v[j][k] && v[i][k] == 1)
            cnt++;
          else if (v[i][k] == 1)
            a++;
          else if (v[j][k] == 1)
            b++;
        }
        if (max(0LL, (n / 2) - a) + max(0LL, (n / 2) - b) <= cnt) {
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    cout << (flag == 1 ? "YES" : "NO") << endl;
  }
}
