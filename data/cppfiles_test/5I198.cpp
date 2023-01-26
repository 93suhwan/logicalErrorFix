#include <bits/stdc++.h>
using namespace std;
int const N = 1e7 + 3;
long long int MOD = 1e9 + 7, fact[N];
const long long inf = (long long)1e18;
const long double PI = 3.14159265358979;
long long int countDivisor(vector<long long int> &v, long long int n) {
  for (long long int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      v.push_back(i);
    } else if (n % i == 0) {
      v.push_back(i);
      v.push_back(n / i);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, j, i, k, tc = 1, p, r, l;
  long long int x, y, z;
  cin >> tc;
  while (tc--) {
    vector<long long int> v;
    map<long long int, long long int> mp, mp2;
    cin >> n;
    n--;
    cout << n / 2 << " " << n << endl;
  }
  return 0;
}
