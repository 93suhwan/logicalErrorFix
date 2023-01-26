#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, m, i, j, k;
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int mi = min(a, b);
    long long int ma = max(a, b);
    long long int dif = ma - mi;
    long long int mhh = ma + dif - mi;
    if (mhh < ma)
      cout << -1;
    else {
      if (c > mhh)
        cout << -1;
      else if (c + dif <= mhh)
        cout << c + dif;
      else
        cout << c - dif;
    }
    cout << endl;
  }
  return 0;
}
