#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int i, j, k, l, m, n, a, b, c, d, u, v, w, t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;
    long long int check = 1;
    for (long long int i = 1; i < n; i++) {
      if (str1[i] == '1' && str2[i] == '1') check = 0;
    }
    if (check)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
