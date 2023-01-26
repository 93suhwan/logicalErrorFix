#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vs = vector<string>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<ll, ll>>;
using ld = double;
const ll MOD = 998244353;
ll add(ll x, ll y) {
  x += y;
  if (x >= MOD) return x - MOD;
  return x;
}
ll sub(ll x, ll y) {
  x -= y;
  if (x < 0) return x + MOD;
  return x;
}
ll mult(ll x, ll y) { return (x * y) % MOD; }
template <typename T>
T signum(T a) {
  return (a > 0) - (a < 0);
}
template <typename T>
T cmp(T a, T b) {
  return signum(a - b);
}
template <typename T>
bool mins(T& lhs, T& rhs) {
  if (rhs < lhs) {
    lhs = rhs;
    return true;
  }
  return false;
}
template <typename T>
bool maxs(T& lhs, T& rhs) {
  if (rhs > lhs) {
    lhs = rhs;
    return true;
  }
  return false;
}
const int MAX = INT_MAX;
void gks(int tc) { printf("Case #%d: ", tc); };
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<pair<int, int>> like;
    vector<pair<int, int>> dislike;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        dislike.push_back({a[i], i});
      } else {
        like.push_back({a[i], i});
      }
    }
    sort(like.begin(), like.end());
    sort(dislike.begin(), dislike.end());
    vector<int> ans(n);
    vector<int> b(dislike.size());
    vector<int> c(like.size());
    iota(b.begin(), b.end(), 1);
    iota(c.begin(), c.end(), dislike.size() + 1);
    for (int i = 0; i < (int)dislike.size(); ++i) {
      ans[dislike[i].second] = b[i];
    }
    for (int i = 0; i < (int)like.size(); ++i) {
      ans[like[i].second] = c[i];
    }
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}
