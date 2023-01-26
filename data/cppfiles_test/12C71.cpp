#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  long long int testcases;
  cin >> testcases;
  while (testcases--) {
    long long int n, k, i, j, sum = 0, cnt = 0, ans = 0, m;
    cin >> n >> m >> k;
    long long int mx, mn;
    if (n % 2 != 0) {
      mx = (m / 2) * n;
      mn = m / 2;
      if (mx % 2 == 0) {
        if (k >= mn and k <= mx and k % 2 == 0)
          cout << "YES" << '\n';
        else
          cout << "NO" << '\n';
      } else {
        if (k >= mn and k <= mx and k % 2 != 0)
          cout << "YES" << '\n';
        else
          cout << "NO" << '\n';
      }
    } else {
      mx = (m / 2) * n;
      mn = 0;
      if (mx % 2 == 0) {
        if (k >= mn and k <= mx and k % 2 == 0)
          cout << "YES" << '\n';
        else
          cout << "NO" << '\n';
      } else {
        if (k >= mn and k <= mx and k % 2 != 0)
          cout << "YES" << '\n';
        else
          cout << "NO" << '\n';
      }
    }
  }
}
