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
    vector<int> a_max;
    ll v_max = -1;
    for (int i = (0); i < (tr[m]); ++i) {
      auto a = d;
      vector<int> c(m);
      ll ii = i;
      for (int j = (0); j < (m); ++j) {
        c[j] = ii % 3;
        ii /= 3;
      }
      bool valid = true;
      for (int j = m - 1; j >= 0; j--) {
        if (c[j] == 1) {
          if (j == m - 1) {
            valid = false;
            break;
          }
          if (a[j + 1] == 0) {
            valid = false;
            break;
          }
          a[j + 1]--;
          a[j] += 10;
        } else if (c[j] == 2) {
          if (j == m - 1) {
            valid = false;
            break;
          }
          if (a[j + 1] < 2) {
            valid = false;
            break;
          }
          a[j + 1] -= 2;
          a[j] += 20;
        }
      }
      if (!valid) continue;
      ll tmp = 0;
      for (int j = m - 1; j >= 0; j--) {
        tmp += a[j];
      }
      ll v = 0;
      if (tmp >= n) {
        for (int j = m - 1; j >= 0; j--) {
          v += a[j] * ps[j];
        }
        if (v > v_max) {
          v_max = v;
          a_max = a;
        }
      }
    }
    auto a = a_max;
    vector<ll> ans;
    for (int j = m - 1; j >= 0; j--) {
      int aj = a[j];
      for (int k = (0); k < (aj); ++k) {
        if (ans.size() < n - 3 || a[j] <= 10) {
          ans.push_back(qs[j]);
          a[j]--;
        } else if (ans.size() == n - 3 && a[j] > 18) {
          ans.push_back(9 * qs[j]);
          a[j] -= 9;
        } else {
          ans.push_back(9 * qs[j]);
          a[j] -= 9;
        }
        if (ans.size() == n - 1) {
          ll tmp = 0;
          for (int l = j; l >= 0; l--) {
            tmp += a[l] * qs[l];
          }
          ans.push_back(tmp);
          break;
        }
      }
      if (ans.size() == n) break;
    }
    for (int i = (0); i < (n); ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
