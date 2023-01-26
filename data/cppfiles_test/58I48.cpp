#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(n, 0));
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++) cin >> v[i][j];
    int ans = 1;
    for (int j = 0; j < n; j++)
      if (v[0][j] == 1 && v[1][j] == 1) ans = 0;
    if (ans)
      cout << "YES/n";
    else
      cout << "NO\n";
  }
}
