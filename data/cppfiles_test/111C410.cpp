#include <bits/stdc++.h>
using namespace std;
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
long long inf = 2e18;
char nl = '\n';
long long mod = 1e9 + 7;
vector<string> ans;
bool f = true;
void rec(long long i, long long len, long long bal, string s) {
  if (((long long)(s).size()) == len) {
    ans.push_back(s);
    if (((long long)(ans).size()) > len / 2) {
      f = false;
    }
  }
  if (!f) return;
  string t = s;
  if (bal > 0) {
    t += ')';
    rec(i + 1, len, bal - 1, t);
    if (!f) return;
  }
  if (!f) return;
  string t1 = s;
  t1 += '(';
  long long ost = len - i - 1;
  if (ost > bal) {
    rec(i + 1, len, bal + 1, t1);
    if (!f) return;
  }
}
void solve() {
  long long n;
  cin >> n;
  f = true;
  rec(0, n * 2, 0, "");
  for (long long i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  ans.clear();
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto begin = std::chrono::high_resolution_clock::now();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
  return 0;
}
