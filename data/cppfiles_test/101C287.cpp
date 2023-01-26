#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long N = 200005;
vector<long long> b, r;
int x[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (long long i = (1); i < (n + 1); i++) {
      cin >> x[i];
    }
    string s;
    cin >> s;
    s = 'a' + s;
    for (long long i = (1); i < ((long long)s.size()); i++) {
      if (s[i] == 'B') {
        b.push_back(x[i]);
      } else {
        r.push_back(x[i]);
      }
    }
    sort(b.begin(), b.end());
    sort(r.begin(), r.end());
    bool check = true;
    for (long long i = (0); i < ((long long)b.size()); i++) {
      if (b[i] >= i + 1) {
        continue;
      }
      check = false;
      break;
    }
    for (long long i = (0); i < ((long long)r.size()); i++) {
      if (r[i] <= i + 1 + (long long)b.size()) {
        continue;
      }
      check = false;
      break;
    }
    cout << "NO\0YES" + 3 * (check) << endl;
    b.clear();
    r.clear();
  }
  return 0;
}
