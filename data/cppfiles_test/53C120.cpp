#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vpi = vector<pii>;
using vvpi = vector<vpi>;
using vpl = vector<pll>;
using vvpl = vector<vpl>;
const int inf = 1 << 30;
const ll INF = 1LL << 58;
void solve() {
  int n;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  set<int> se;
  for (int i = 0; i < (int)(n); i++) {
    if (s[i] != c) se.insert(i + 1);
  }
  if (se.empty()) {
    cout << 0 << endl;
    return;
  }
  for (int i = 1; i < (int)(n + 1); i++) {
    bool flag = true;
    for (int j = i; j <= n; j += i) {
      if (se.count(j)) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << 1 << endl;
      cout << i << endl;
      return;
    }
  }
  cout << 2 << endl;
  cout << n << " " << n - 1 << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < (int)(t); i++) {
    solve();
  }
}
