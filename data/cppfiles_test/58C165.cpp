#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  ll q, n;
  string s1, s2;
  vector<bool> ok1, ok2;
  cin >> q;
  while (q--) {
    cin >> n >> s1 >> s2;
    ok1.resize(0);
    ok2.resize(0);
    ok1.resize(n, 0);
    ok2.resize(n, 0);
    ok1[0] = true;
    if (s2[0] == '0') ok2[0] = true;
    for (int i = 1; i < n; ++i) {
      if (ok1[i - 1] || ok2[i - 1]) {
        if (s1[i] == '0') ok1[i] = true;
        if (s2[i] == '0') ok2[i] = true;
      }
    }
    if (ok2[n - 1]) {
      cout << "YES" << endl;
      ;
    } else {
      cout << "NO" << endl;
      ;
    }
  }
  return 0;
}
