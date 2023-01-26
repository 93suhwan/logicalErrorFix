#include <bits/stdc++.h>
using namespace std;
long long n, i, c, k, L, R, j, c1, c2, a[5007], test;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> s;
    c1 = 0;
    for (j = 0; j < s.size(); j++) {
      if (s[j] == 'N') c1++;
    }
    if (c1 == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
