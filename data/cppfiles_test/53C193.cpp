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
  set<char> se;
  for (auto x : s) se.insert(x);
  if (se.size() == 1 && s[0] == c) {
    cout << 0 << endl;
    return;
  }
  for (int i = (n + 2) / 2; i < (int)(n + 1); i++) {
    if (s[i - 1] == c) {
      cout << 1 << endl;
      cout << i << endl;
      return;
    }
  }
  cout << 2 << endl;
  if (n % 2 == 0)
    cout << 2 << " " << n - 1 << endl;
  else
    cout << 2 << " " << n << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < (int)(t); i++) {
    solve();
  }
}
