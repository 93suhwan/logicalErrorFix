#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long INF = 0x3f3f3f3f;
long long inf = pow(10, 18);
long long modulo = 998244353;
void deal() {
  long long t;
  cin >> t;
  for (long long l = 0; l < t; l++) {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long> > arr(n, vector<long long>(2));
    vector<vector<long long> > took(n, vector<long long>(2, 0));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 2; j++) {
        cin >> arr[i][j];
      }
    }
    vector<long long> s(2, 0);
    for (long long i = 0; i < n; i++) {
      long long cr = m;
      for (long long j = 0; j < 2; j++) {
        long long mn = min(cr, arr[i][j]);
        took[i][j] = mn;
        cr -= mn;
        s[j] += arr[i][j] - mn;
      }
    }
    for (long long i = 0; i < n; i++) {
      if (s[1] > s[0]) {
        long long dif = (s[1] - s[0]) / 2;
        long long mn = min({dif, took[i][0], arr[i][1] - took[i][1]});
        took[i][0] -= mn;
        took[i][1] += mn;
        s[1] -= mn;
        s[0] += mn;
      }
    }
    cout << abs(s[0] - s[1]) << '\n';
    for (long long i = 0; i < n; i++) {
      cout << took[i][0] << ' ' << took[i][1] << '\n';
    }
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  deal();
}
