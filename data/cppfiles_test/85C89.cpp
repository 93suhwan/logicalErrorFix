#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int, int>;
using vMii = vector<Mii>;
using Si = set<int>;
using vSi = vector<Si>;
using vvSi = vector<vSi>;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    bool one = true;
    for (char c : s)
      if (c == '0') one = false;
    if (one)
      cout << 0 << '\n';
    else {
      int first = -1;
      for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
          first = i;
          break;
        }
      }
      int last = -1;
      for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
          last = i;
          break;
        }
      }
      bool two = false;
      for (int i = first; i <= last; ++i) {
        if (s[i] == '1') two = true;
      }
      cout << (two ? 2 : 1) << '\n';
    }
  }
}
