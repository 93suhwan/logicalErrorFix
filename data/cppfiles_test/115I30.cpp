#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "[";
  os << p.first;
  os << ", ";
  os << p.second;
  os << "]";
  return os;
}
struct ModInt;
vector<ModInt> inverse();
using ModType = long long;
struct ModInt {
  static inline vector<ModInt> precalcInverse;
  static void precalc() { precalcInverse = inverse(); }
  static inline ModType mod = 998244353;
  ModType val;
  ModInt(ModType v = 0) : val(v % mod) {}
  static void setMod(ModType m) {
    mod = m;
    if (precalcInverse.size() > 0) {
      precalcInverse = inverse();
    }
  }
  ModInt& operator+=(ModInt a) {
    if ((val += a.val) >= mod) val -= mod;
    return *this;
  }
  ModInt& operator-=(ModInt a) {
    if ((val -= a.val) < 0) val += mod;
    return *this;
  }
  ModInt& operator*=(ModInt a) {
    val = (val * a.val) % mod;
    return *this;
  }
  ModInt& operator/=(ModInt a) {
    if (precalcInverse.size() > a.val) {
      *this *= precalcInverse[a.val];
      return *this;
    }
    ModType u = 1, v = a.val, s = 0, t = mod;
    while (v) {
      ModType q = t / v;
      swap(s -= u * q, u);
      swap(t -= v * q, v);
    }
    a.val = (s < 0 ? s + mod : s);
    val /= t;
    return (*this) *= a;
  }
  ModInt inv() const { return ModInt(1) /= (*this); }
  bool operator<(ModInt x) const { return val < x.val; }
};
ostream& operator<<(ostream& os, ModInt a) {
  os << a.val;
  return os;
}
ModInt operator+(ModInt a, ModInt b) { return a += b; }
ModInt operator-(ModInt a, ModInt b) { return a -= b; }
ModInt operator*(ModInt a, ModInt b) { return a *= b; }
ModInt operator/(ModInt a, ModInt b) { return a /= b; }
ModInt mpow(ModInt a, ModType e) {
  ModInt x(1);
  for (; e > 0; e /= 2) {
    if (e % 2 == 1) x *= a;
    a *= a;
  }
  return x;
}
vector<ModInt> inverse() {
  ModType mod = ModInt::mod;
  vector<ModInt> inv(mod);
  inv[1].val = 1;
  for (ModType a = 2; a < mod; ++a)
    inv[a] = inv[mod % a] * ModInt(mod - mod / a);
  return inv;
}
ModInt stringToModInt(string s) {
  ModType val = 0;
  for (int i = 0; i < s.size(); ++i)
    val = (val * 10 + (s[i] - '0')) % ModInt::mod;
  return ModInt(val);
}
int getpar(int r, int c, int val) { return (r + c + val) % 2; }
int solve() {
  int n, m, k;
  cin >> n >> m >> k;
  map<pair<int, int>, int> matr;
  vector<vector<int>> rowpar(2, vector<int>(n, 0));
  int nrowpar[2] = {0, 0};
  int nrowfree = n;
  vector<vector<int>> colpar(2, vector<int>(m, 0));
  int ncolpar[2] = {0, 0};
  int ncolfree = m;
  int nerrorc = 0, nerrorr = 0;
  for (int i = 0; i < k; ++i) {
    int r, c, op;
    cin >> r >> c >> op;
    r--;
    c--;
    auto it = matr.find({r, c});
    if (it != matr.end()) {
      int val = it->second;
      int par = getpar(r, c, val);
      rowpar[par][r]--;
      if (rowpar[par][r] == 0) {
        nrowpar[par]--;
        if (rowpar[1 - par][r] != 0) {
          nerrorr--;
        }
        if (rowpar[1 - par][r] == 0) {
          nrowfree++;
        }
      }
      colpar[par][c]--;
      if (colpar[par][c] == 0) {
        ncolpar[par]--;
        if (colpar[1 - par][c] != 0) {
          nerrorc--;
        }
        if (colpar[1 - par][c] == 0) {
          ncolfree++;
        }
      }
      matr.erase(it);
    }
    if (op != -1) {
      matr[{r, c}] = op;
      int par = getpar(r, c, op);
      if (rowpar[par][r] == 0) {
        nrowpar[par]++;
        if (rowpar[1 - par][r] != 0) {
          nerrorr++;
        }
        if (rowpar[1 - par][r] == 0) {
          nrowfree--;
        }
      }
      rowpar[par][r]++;
      if (colpar[par][c] == 0) {
        ncolpar[par]++;
        if (colpar[1 - par][c] != 0) {
          nerrorc++;
        }
        if (colpar[1 - par][c] == 0) {
          ncolfree--;
        }
      }
      colpar[par][c]++;
    }
    ModInt ans = 0;
    ModInt choser = 1;
    if (nerrorc != 0 && nerrorr != 0) {
      cout << 0 << "\n";
      continue;
    }
    ModInt ansr = 0;
    ModInt ansc = 0;
    if (nerrorc == 0) {
      ansc = mpow(2, ncolfree);
    }
    if (nerrorr == 0) {
      ansr = mpow(2, nrowfree);
    }
    ans = ansr + ansc;
    if (matr.empty()) {
      ans -= 1;
    }
    if (nerrorr == 0 && nerrorc == 0) {
      ans -= 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ntest = 1;
  for (int test = 0; test < ntest; ++test) {
    solve();
  }
  return 0;
}
