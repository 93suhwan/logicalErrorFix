#include <bits/stdc++.h>
using namespace std;
const long double E = 1e-6;
const long long INF = 9e18;
const long long M = (long long)1e9 + 7;
signed main() {
  FILE *pFile = fopen("input.txt", "r");
  if (pFile != nullptr) freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long long> u, v;
    for (long long i = 0; i < n; i++) {
      char c;
      cin >> c;
      if (c == '0')
        u.push_back(a[i]);
      else
        v.push_back(a[i]);
    }
    for (auto val : v) cout << val << " ";
    for (auto val : u) cout << val << " ";
    cout << "\n";
  }
}
