#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, k;
    cin >> n >> m >> k;
    int minn, maxx;
    minn = (n % 2 == 1 ? m / 2 : 0);
    maxx = n * m / 2 - (m % 2 == 1 ? n / 2 : 0);
    if (minn <= k && k <= maxx && (k - minn) % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
