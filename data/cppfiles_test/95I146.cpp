#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using PR = pair<T, T>;
template <class T>
int lwb(V<T>& a, const T& b) {
  return int(lower_bound(begin(a), end(a), b) - begin(a));
}
vector<int> getDigits(ll n) {
  vector<int> a;
  while (n > 0) {
    a.push_back(n % 10);
    n /= 10;
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<ll> ps(11), qs(11), tr(11);
  for (int i = (0); i < (11); ++i) {
    if (i == 0)
      tr[0] = 1;
    else
      tr[i] = tr[i - 1] * 3;
  }
  for (int i = (0); i < (11); ++i) {
    if (i == 0)
      ps[i] = 1, qs[i] = 1;
    else
      ps[i] = ps[i - 1] * 11, qs[i] = qs[i - 1] * 10;
  }
  int tt;
  cin >> tt;
  for (int ti = 0; ti < tt; ti++) {
    ll s, n;
    cin >> s >> n;
    if (n == 1) {
      cout << s << endl;
      continue;
    }
    auto d = getDigits(s);
    int m = d.size();
    vector<vector<int>> ans;
    ans.push_back(d);
    for (int i = (0); i < (n - 1); ++i) {
      int mn = 100;
      int i_mn = -1;
      for (int i = (0); i < (ans.size()); ++i) {
        auto& a = ans[i];
        if (a.size() == 1 && a[0] == 1) continue;
        for (int j = (0); j < (a.size()); ++j) {
          if (a[j] > 0) {
            mn = min(mn, j);
            i_mn = i;
            break;
          }
        }
      }
      auto& a = ans[i_mn];
      vector<int> tmp;
      for (int j = (0); j < (a.size()); ++j) {
        if (a[j] > 0) {
          tmp.push_back(1);
          a[j]--;
          if (a[j] == 0 && j > 0) {
            a[j - 1] = 9;
          }
          if (a[j] == 0 && j == a.size() - 1) a.pop_back();
          break;
        }
        tmp.push_back(0);
      }
      ans.push_back(tmp);
    }
    for (int i = (0); i < (n); ++i) {
      if (i > 0) cout << " ";
      for (int j = (0); j < (ans[i].size()); ++j)
        cout << ans[i][ans[i].size() - 1 - j];
    }
    cout << endl;
  }
}
