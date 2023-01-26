#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
bool sortBysec(pair<long long int, long long int> a,
               pair<long long int, long long int> b) {
  return a.second < b.second;
}
long long int binExp(long long int a, long long int n) {
  long long int res = 1;
  while (n) {
    if (n % 2 == 1) {
      res = (res * a) % mod;
      n--;
    } else {
      a = (a * a) % mod;
      n = n / 2;
    }
  }
  return res;
}
long long int power(long long int n, long long int m) {
  long long int ans = 1;
  while (m) {
    ans *= n;
    m--;
  }
  return ans;
}
long long int cntdig(long long int n) {
  long long int cnt = 0;
  while (n) {
    cnt++;
    n = n / 10;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1, i = 0, n, m, j, l, k, x, y, z, d, a, b, c, p, e, q,
                tt = 0, r;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2 == 0) {
      p = n / 2;
      for (i = 0; i < p; i++) {
        cout << "a";
      }
      cout << "b";
      for (i = 0; i < p - 1; i++) {
        cout << "a";
      }
      cout << endl;
    } else {
      p = n / 2;
      for (i = 0; i < p; i++) {
        cout << "a";
      }
      cout << "bc";
      for (i = 0; i < p - 1; i++) {
        cout << "a";
      }
      cout << endl;
    }
  }
  return 0;
}
