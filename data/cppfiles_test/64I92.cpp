#include <bits/stdc++.h>
using namespace std;
using LL = long long;
class ZAlgorithm {
 public:
  ZAlgorithm(string _s) : s(std::move(_s)), n(s.size()), z(n) {
    int L = 0, R = 0;
    for (int i = 1; i < n; ++i) {
      if (i > R) {
        L = R = i;
        while (R < n && s[R - L] == s[R]) ++R;
        z[i] = R - L;
        --R;
      } else {
        int k = i - L;
        if (z[k] < R - i + 1)
          z[i] = z[k];
        else {
          L = i;
          while (R < n && s[R - L] == s[R]) ++R;
          z[i] = R - L;
          --R;
        }
      }
    }
  }
  string s;
  int n;
  vector<int> z;
};
const int D = 3;
LL md[D] = {998244353, 1000000007, 1000000009};
class Mint {
 public:
  Mint() {
    for (int i = 0; i < D; ++i) x[i] = 0;
  }
  Mint(LL a) {
    for (int i = 0; i < D; ++i) {
      x[i] = a % md[i];
    }
  }
  Mint operator+(const Mint& t) {
    Mint a;
    for (int i = 0; i < D; ++i) {
      a.x[i] = (x[i] + t.x[i]) % md[i];
    }
    return a;
  }
  Mint operator-(const Mint& t) {
    Mint a;
    for (int i = 0; i < D; ++i) {
      a.x[i] = (x[i] - t.x[i] + md[i]) % md[i];
    }
    return a;
  }
  Mint operator*(const Mint& t) {
    Mint a;
    for (int i = 0; i < D; ++i) {
      a.x[i] = (x[i] * t.x[i]) % md[i];
    }
    return a;
  }
  bool operator==(const Mint& t) {
    bool same = true;
    for (int i = 0; i < D; ++i) {
      same &= x[i] == t.x[i];
    }
    return same;
  }
  LL x[D];
};
const int MAXN = 500010;
Mint p10[MAXN];
Mint v[MAXN];
Mint GetV(int l, int r) { return v[r + 1] - v[l] * p10[r + 1 - l]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, x;
  cin >> s >> x;
  int ns = s.size(), nx = x.size();
  p10[0] = 1;
  for (int i = 1; i <= ns; ++i) {
    p10[i] = p10[i - 1] * 10;
  }
  for (int i = 0; i < ns; ++i) {
    v[i + 1] = v[i] * 10 + int(s[i] - '0');
  }
  Mint mx = 0;
  for (int i = 0; i < nx; ++i) mx = mx * 10 + int(x[i] - '0');
  for (int i = 0; i < ns; ++i) {
    if (i + nx - 1 + nx - 1 > ns) break;
    if (GetV(i, i + nx - 2) + GetV(i + nx - 1, i + 2 * nx - 3) == mx) {
      cout << i + 1 << " " << i + nx - 1 << endl;
      cout << i + nx << " " << i + 2 * nx - 2 << endl;
      return 0;
    }
  }
  ZAlgorithm zg(x + s);
  for (int i = 0; i < ns; ++i) {
    if (i + nx > ns) break;
    Mint a = GetV(i, i + nx - 1);
    int len = zg.z[nx + i];
    if (i >= nx - len) {
      Mint b = GetV(i - (nx - len), i - 1);
      if (a + b == mx) {
        cout << i - (nx - len) + 1 << " " << i << endl;
        cout << i + 1 << " " << i + nx << endl;
        return 0;
      }
    }
    if (i + nx - 1 + nx - len - 1 < ns) {
      Mint b = GetV(i + nx, i + nx + nx - len - 1);
      if (a + b == mx) {
        cout << i + 1 << " " << i + nx << endl;
        cout << i + nx + 1 << " " << i + nx + nx - len << endl;
        return 0;
      }
    }
    if (i >= nx - len - 1) {
      Mint b = GetV(i - (nx - len - 1), i - 1);
      if (a + b == mx) {
        cout << i - (nx - len - 1) + 1 << " " << i << endl;
        cout << i + 1 << " " << i + nx << endl;
        return 0;
      }
    }
    if (i + nx - 1 + nx - len - 2 < ns) {
      Mint b = GetV(i + nx, i + nx + nx - len - 2);
      if (a + b == mx) {
        cout << i + 1 << " " << i + nx << endl;
        cout << i + nx + 1 << " " << i + nx + 1 + nx - len - 2 << endl;
        return 0;
      }
    }
  }
  return 0;
}
