#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int a = power(x, y / 2, m);
  if (y % 2) {
    return (a * ((a * x) % m)) % m;
  } else {
    return (a * a) % m;
  }
}
long long int mod_inverse(long long int x, long long int m) {
  return power(x, m - 2, m);
}
long long int fact(long long int n, long long int m) {
  if (n <= 1) return 1;
  return (fact(n - 1, m) * n) % m;
}
long long int ncr(long long int n, long long int r, long long int m) {
  if (r > n || r < 0) return 0;
  if (n < 0) return 0;
  long long int n1 = 1, d1 = 1, d2 = 1;
  n1 = fact(n, m);
  d1 = fact(r, m);
  d2 = fact(n - r, m);
  long long int ans = mod_inverse((d1 * d2) % m, m);
  ans = (ans * n1) % m;
  return ans;
}
class solver {
 public:
  void solve() {
    int w, h;
    cin >> w >> h;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a, b;
    cin >> a >> b;
    int lx, ly;
    lx = abs(x1 - x2);
    ly = abs(y1 - y2);
    if ((lx + a) <= w)
      lx = 1;
    else
      lx = 0;
    if ((ly + b) <= h)
      ly = 1;
    else
      ly = 0;
    int x, y;
    x = a;
    y = b;
    set<int> st;
    if (x1 < x && y1 < y) {
      if (lx) {
        st.insert(abs(x1 - x));
      }
      if (ly) {
        st.insert(abs(y1 - y));
      }
    } else {
      st.insert(0);
    }
    x = a;
    y = h - b;
    if (x1 < x && y2 > y) {
      if (lx) {
        st.insert(abs(x1 - x));
      }
      if (ly) {
        st.insert(abs(y2 - y));
      }
    } else {
      st.insert(0);
    }
    x = w - a;
    y = b;
    if (x2 > x && y1 < y) {
      if (lx) {
        st.insert(abs(x2 - x));
      }
      if (ly) {
        st.insert(abs(y1 - y));
      }
    } else {
      st.insert(0);
    }
    x = w - a;
    y = h - b;
    if (x2 > x && y2 > y) {
      if (lx) {
        st.insert(abs(x2 - x));
      }
      if (ly) {
        st.insert(abs(y2 - y));
      }
    } else {
      st.insert(0);
    }
    if (st.size() == 0) {
      cout << -1 << '\n';
      return;
    }
    auto itr = st.begin();
    int tm = *itr;
    double tmm = (double)(tm);
    cout << fixed << setprecision(8) << tmm << '\n';
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  cin >> test;
  while (test--) {
    solver o;
    o.solve();
  }
}
