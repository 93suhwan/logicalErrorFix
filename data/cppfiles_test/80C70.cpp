#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1e6;
const long long MOD = 1e9 + 7;
using namespace std;
long long q, x, y, z, n, m, a[KL], mn = 1e9, mx = -1e9, ans;
string t;
vector<long long> vec;
set<long long> s;
map<long long, long long> mp;
int main() {
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld", &n);
    cin >> t;
    int pos = (n + 1) / 2;
    bool ok = false;
    for (int i = pos; i < n; i++) {
      if (t[i] == '0') {
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
        ok = 1;
        break;
      }
    }
    if (ok) continue;
    if (t[pos - 1] == '1') {
      cout << pos << " " << n - 1 << " " << pos + 1 << " " << n << endl;
    } else {
      cout << pos << " " << n << " " << pos + 1 << " " << n << endl;
    }
  }
  return 0;
}
