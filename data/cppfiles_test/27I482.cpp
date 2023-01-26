#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 9;
const long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, m, k;
    cin >> n >> m >> k;
    k--;
    if (m < n - 1 || m > n * (n - 1) / 2)
      cout << "NO\n";
    else {
      long long dis;
      if (m == n * (n - 1) / 2)
        dis = 1;
      else
        dis = 2;
      if (dis < k)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
