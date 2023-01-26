#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll mod = 1000000007;
const ll inf = 1e9;
ll rng(ll l, ll u) { return l + (ll)rand() % (u - l + 1); }
ll bpow(ll a, int n) {
  return n ? n & 1 ? a * bpow(a, n - 1) : bpow(a * a, n >> 1) : 1;
}
vector<int> stupid(int n, vector<int> a) {
  vector<int> ans = {0};
  set<int> s = {0};
  for (int i = 1; i < pow(2, n); ++i) {
    vector<int> m;
    int mask = i, j = n - 1;
    while (mask) {
      if (mask % 2) {
        m.push_back(j);
      }
      mask /= 2;
      j--;
    }
    reverse(m.begin(), m.end());
    int x = a[m[0]];
    bool flag = 1;
    for (int j = 1; j < m.size(); ++j) {
      if (a[m[j]] <= a[m[j - 1]]) {
        flag = 0;
        break;
      }
      x ^= a[m[j]];
    }
    if (flag && !s.count(x)) {
      ans.push_back(x);
      s.insert(x);
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> ans = {0}, used(513, 0), m(513, 0);
  used[0] = true;
  for (int i = 0; i < n; ++i) {
    int sz = ans.size();
    for (int j = 0; j < sz; ++j) {
      int res = ans[j];
      if (m[res] < a[i]) {
        int new_res = res ^ a[i];
        if (m[new_res]) {
          m[new_res] = min(a[i], m[new_res]);
        } else {
          if (new_res) m[new_res] = a[i];
        }
        if (!used[new_res]) {
          ans.push_back(new_res);
          used[new_res] = true;
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
    cout << endl;
  }
}
