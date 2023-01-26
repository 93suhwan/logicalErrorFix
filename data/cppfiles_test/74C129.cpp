#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 2012;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void setIO(string name = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  if (name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
int main() {
  setIO("");
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    int n = a + b;
    set<int> ans;
    if (n % 2 == 0) {
      int x = n / 2;
      for (int i = a - x; i <= b + x; i += 2) ans.insert(i);
    } else {
      int x = (n + 1) / 2;
      for (int i = a - x; i <= x + b; i++) ans.insert(i);
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << " ";
    cout << endl;
  }
}
