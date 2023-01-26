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
  int ans = 2;
  vi va = {n, n - 1};
  vi vec;
  vi ju(n + 1), cnt(n + 1);
  for (int i = 2; i < (int)(n + 1); i++) {
    for (int j = i; j <= n; j += i) {
      if (cnt[j] == 0) {
        cnt[j] = i;
      }
    }
  }
  vb flag(n + 1);
  flag[1] = true;
  for (int i = 0; i < (int)(n); i++) {
    if (s[i] != c) {
      int j = i + 1;
      while (j > 1) {
        flag[cnt[j]] = true;
        j /= cnt[j];
      }
    }
  }
  for (int i = 2; i < (int)(n + 1); i++) {
    if (!flag[cnt[i]]) {
      ans = 1;
      va = {i};
      break;
    }
  }
  cout << ans << endl;
  for (auto i : va) cout << i << " ";
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < (int)(t); i++) {
    solve();
  }
}
