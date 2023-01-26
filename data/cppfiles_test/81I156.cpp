#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
mt19937 rnd(179);
long long mod = 1000000007;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long X;
  cin >> X;
  while (X--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<long long> prs{0};
    for (long long i = 0; i < n; ++i) {
      if (s[i] == '+') {
        if (i % 2 == 1) {
          prs.push_back(prs[i] - 1);
        } else {
          prs.push_back(prs[i] + 1);
        }
      } else {
        if (i % 2 == 1) {
          prs.push_back(prs[i] + 1);
        } else {
          prs.push_back(prs[i] - 1);
        }
      }
    }
    for (long long i = 0; i < m; ++i) {
      long long l, r;
      cin >> l >> r;
      long long k = prs[r] - prs[l - 1];
      if (k == 0) {
        cout << 0 << '\n';
      } else {
        if (k % 2 == 1) {
          cout << 1 << '\n';
        } else {
          cout << 2 << '\n';
        }
      }
    }
  }
}
