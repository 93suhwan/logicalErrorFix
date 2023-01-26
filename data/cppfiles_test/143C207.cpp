#include <bits/stdc++.h>
using namespace std;
long long dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
long long dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
class pa3 {
 public:
  long long x;
  long long y, z;
  pa3(long long x = 0, long long y = 0, long long z = 0) : x(x), y(y), z(z) {}
  bool operator<(const pa3& p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    return z < p.z;
  }
  bool operator>(const pa3& p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    return z > p.z;
  }
  bool operator==(const pa3& p) const {
    return x == p.x && y == p.y && z == p.z;
  }
  bool operator!=(const pa3& p) const {
    return !(x == p.x && y == p.y && z == p.z);
  }
};
class pa4 {
 public:
  long long x;
  long long y, z, w;
  pa4(long long x = 0, long long y = 0, long long z = 0, long long w = 0)
      : x(x), y(y), z(z), w(w) {}
  bool operator<(const pa4& p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    if (z != p.z) return z < p.z;
    return w < p.w;
  }
  bool operator>(const pa4& p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    if (z != p.z) return z > p.z;
    return w > p.w;
  }
  bool operator==(const pa4& p) const {
    return x == p.x && y == p.y && z == p.z && w == p.w;
  }
};
class pa2 {
 public:
  long long x, y;
  pa2(long long x = 0, long long y = 0) : x(x), y(y) {}
  pa2 operator+(pa2 p) { return pa2(x + p.x, y + p.y); }
  pa2 operator-(pa2 p) { return pa2(x - p.x, y - p.y); }
  bool operator<(const pa2& p) const { return y != p.y ? y < p.y : x < p.x; }
  bool operator>(const pa2& p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const pa2& p) const {
    return abs(x - p.x) == 0 && abs(y - p.y) == 0;
  }
  bool operator!=(const pa2& p) const {
    return !(abs(x - p.x) == 0 && abs(y - p.y) == 0);
  }
};
string itos(long long i) {
  ostringstream s;
  s << i;
  return s.str();
}
long long Gcd(long long v, long long b) {
  if (v == 0) return b;
  if (b == 0) return v;
  if (v > b) return Gcd(b, v);
  if (v == b) return b;
  if (b % v == 0) return v;
  return Gcd(v, b % v);
}
long long extgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
pair<long long, long long> operator+(const pair<long long, long long>& l,
                                     const pair<long long, long long>& r) {
  return {l.first + r.first, l.second + r.second};
}
pair<long long, long long> operator-(const pair<long long, long long>& l,
                                     const pair<long long, long long>& r) {
  return {l.first - r.first, l.second - r.second};
}
ostream& operator<<(ostream& os, const vector<long long>& VEC) {
  for (auto v : VEC) os << v << " ";
  return os;
}
ostream& operator<<(ostream& os, const pair<long long, long long>& PAI) {
  os << PAI.first << " : " << PAI.second;
  return os;
}
ostream& operator<<(ostream& os, const pa3& PAI) {
  os << PAI.x << " : " << PAI.y << " : " << PAI.z;
  return os;
}
ostream& operator<<(ostream& os, const pa4& PAI) {
  os << PAI.x << " : " << PAI.y << " : " << PAI.z << " : " << PAI.w;
  return os;
}
ostream& operator<<(ostream& os,
                    const vector<pair<long long, long long> >& VEC) {
  for (auto v : VEC) os << v << " ";
  return os;
}
ostream& operator<<(ostream& os, const vector<pa3>& VEC) {
  for (auto v : VEC) {
    os << v << " ";
    os << endl;
  }
  return os;
}
long long beki(long long wa, long long rr, long long warukazu) {
  if (rr == 0) return 1 % warukazu;
  if (rr == 1) return wa % warukazu;
  wa %= warukazu;
  if (rr % 2 == 1)
    return ((long long)beki(wa, rr - 1, warukazu) * (long long)wa) % warukazu;
  long long zx = beki(wa, rr / 2, warukazu);
  return (zx * zx) % warukazu;
}
long long pr[2521000];
long long inv[2521000];
const long long mod = 998244353;
long long comb(long long nn, long long rr) {
  if (nn == -1 && rr == -1) return 1;
  if (rr < 0 || rr > nn || nn < 0) return 0;
  long long r = pr[nn] * inv[rr];
  r %= mod;
  r *= inv[nn - rr];
  r %= mod;
  return r;
}
void gya(long long ert) {
  pr[0] = 1;
  for (long long i = 1; i <= ert; i++) {
    pr[i] = ((long long)pr[i - 1] * i) % mod;
  }
  inv[ert] = beki(pr[ert], mod - 2, mod);
  for (long long i = ert - 1; i >= 0; i--) {
    inv[i] = (long long)inv[i + 1] * (i + 1) % mod;
  }
}
long long beki(long long a, long long b) {
  long long ANS = 1;
  long long be = a % mod;
  while (b) {
    if (b & 1) {
      ANS *= be;
      ANS %= mod;
    }
    be *= be;
    be %= mod;
    b /= 2;
  }
  return ANS;
}
struct BV {
 private:
 public:
  long long N;
  vector<long long> RAN;
  vector<long long> SEL1;
  vector<long long> SEL0;
  long long k0 = 0, k1 = 0;
  vector<bool> VEC;
  void shoki1(long long NN) {
    N = NN;
    VEC.resize(N, false);
    RAN.resize(N + 1, 0);
  }
  void setbit(long long i) { VEC[i] = 1; }
  void resetbit(long long i) { VEC[i] = 0; }
  void shoki2() {
    for (long long i = 0; i < N; i++) {
      if (VEC[i]) {
        RAN[i] = k1;
        k1++;
      } else {
        RAN[i] = k0;
        k0++;
      }
    }
    SEL1.resize(k1);
    SEL0.resize(k0);
    k0 = 0, k1 = 0;
    for (long long i = 0; i < N; i++) {
      if (VEC[i]) {
        SEL1[k1] = i;
        k1++;
      } else {
        SEL0[k0] = i;
        k0++;
      }
    }
  }
  long long rank(long long it) { return RAN[it]; }
  long long rank0(long long it) {
    if (it == N) return k0;
    if (VEC[it])
      return it - RAN[it];
    else
      return RAN[it];
  }
  long long rank1(long long it) {
    if (it == N) return k1;
    if (VEC[it] == 0)
      return it - RAN[it];
    else
      return RAN[it];
  }
  long long select(long long ko, bool b) {
    if (b) {
      if (ko >= k1)
        return -1;
      else
        return SEL1[ko];
    } else {
      if (ko >= k0)
        return -1;
      else
        return SEL0[ko];
    }
  }
  long long access(long long it) { return VEC[it]; }
};
struct wavlet_matrix {
 private:
 public:
  long long N;
  vector<long long> VEC;
  long long d;
  vector<BV> bv;
  vector<long long> zero;
  void shoki1(vector<long long>& input, long long D) {
    VEC = input;
    N = input.size();
    d = D;
    bv.resize(d);
    zero.resize(d);
  }
  void shoki2() {
    for (long long i = d - 1; i >= 0; i--) {
      bv[i].shoki1(N);
      vector<long long> mae, ato;
      for (long long j = 0; j < N; j++) {
        if (VEC[j] & (1ll << i)) {
          ato.push_back(VEC[j]);
          bv[i].setbit(j);
        } else {
          mae.push_back(VEC[j]);
        }
      }
      zero[i] = (long long)mae.size();
      bv[i].shoki2();
      mae.insert(mae.end(), ato.begin(), ato.end());
      swap(VEC, mae);
    }
  }
  long long access(long long r) {
    long long ans = 0;
    for (long long i = d - 1; i >= 0; i--) {
      if (bv[i].access(r)) {
        ans += (1ll << i);
        r = zero[i] + bv[i].rank(r);
      } else {
        r = bv[i].rank(r);
      }
    }
    return ans;
  }
  long long range_rank(long long val, long long l, long long r) {
    for (long long i = d - 1; i >= 0; i--) {
      if (val & (1ll << i)) {
        r = zero[i] + bv[i].rank1(r);
        l = zero[i] + bv[i].rank1(l);
      } else {
        r = bv[i].rank0(r);
        l = bv[i].rank0(l);
      }
      if (l >= r) return 0;
    }
    return r - l;
  }
  long long rank(long long val, long long pos) {
    return range_rank(val, 0, pos + 1);
  }
  long long select(long long val, long long kth) {
    long long l = 0, r = N;
    for (long long i = d - 1; i >= 0; i--) {
      if (val & (1ll << i)) {
        r = zero[i] + bv[i].rank1(r);
        l = zero[i] + bv[i].rank1(l);
      } else {
        r = bv[i].rank0(r);
        l = bv[i].rank0(l);
      }
      if (l + kth >= r) return -1;
    }
    long long pos = l + kth;
    for (long long i = 0; i < d; i++) {
      if (val & (1ll << (i))) {
        pos = bv[i].select(pos - zero[i], 1);
      } else {
        pos = bv[i].select(pos, 0);
      }
    }
    return pos;
  }
  long long x_th_min(long long x, long long l, long long r) {
    long long ans = 0;
    for (long long i = d - 1; i >= 0; i--) {
      long long t1 = bv[i].rank0(l);
      long long t2 = bv[i].rank0(r);
      long long z = t2 - t1;
      if (z > x) {
        l = t1, r = t2;
      } else {
        ans += (1ll << i);
        x -= z;
        l = zero[i] + l - t1;
        r = zero[i] + r - t2;
      }
    }
    return ans;
  }
  long long range_min(long long l, long long r) { return x_th_min(0, l, r); }
  long long range_max(long long l, long long r) {
    return x_th_min(r - l - 1, l, r);
  }
  long long range_count_prefix(long long l, long long r, long long val) {
    if (val <= 0) return 0;
    if (l >= r) return 0;
    val--;
    long long ans = 0;
    for (long long i = d - 1; i >= 0; i--) {
      long long t1 = bv[i].rank0(l);
      long long t2 = bv[i].rank0(r);
      if (val & (1ll << i)) {
        ans += t2 - t1;
        l = zero[i] + l - t1;
        r = zero[i] + r - t2;
      } else {
        l = t1;
        r = t2;
      }
    }
    ans += r - l;
    return ans;
  }
  long long range_count(long long l, long long r, long long vl, long long vr) {
    if (vr <= vl) return 0;
    if (r <= l) return 0;
    return range_count_prefix(l, r, vr) - range_count_prefix(l, r, vl);
  }
  long long range_bound_max(long long l, long long r, long long val) {
    if (l >= r) return -1;
    long long dep = -1;
    long long cl = -1;
    long long cr = -1;
    long long cur = 0;
    long long ima = 0;
    for (long long i = d - 1; i >= 0; i--) {
      if (i == 0) {
        if (val & 1) {
          if (l < r) {
            dep = 0;
            cl = l, cr = r;
            cur = ima;
          }
        } else {
          long long t1 = bv[i].rank0(l);
          long long t2 = bv[i].rank0(r);
          if (t1 < t2) return ima;
        }
        break;
      }
      if (val & (1ll << i)) {
        long long t1 = bv[i].rank0(l);
        long long t2 = bv[i].rank0(r);
        if (t1 != t2) {
          dep = i - 1;
          cl = t1, cr = t2;
          cur = ima;
        }
        l = zero[i] + l - t1;
        r = zero[i] + r - t2;
        ima += (1ll << i);
      } else {
        long long t1 = bv[i].rank0(l);
        long long t2 = bv[i].rank0(r);
        l = t1, r = t2;
      }
    }
    if (dep == -1) return -1;
    ima = cur;
    l = cl, r = cr;
    for (long long i = dep; i >= 0; i--) {
      long long t1 = bv[i].rank0(l);
      long long t2 = bv[i].rank0(r);
      if (r - l > t2 - t1) {
        ima += (1ll << i);
        l = zero[i] + l - t1;
        r = zero[i] + r - t2;
      } else {
        l = t1, r = t2;
      }
    }
    return ima;
  }
  long long range_bound_min(long long l, long long r, long long val) {
    if (l >= r) return -1;
    long long dep = -1;
    long long cl = -1;
    long long cr = -1;
    long long cur = 0;
    long long ima = 0;
    for (long long i = d - 1; i >= 0; i--) {
      if (i == 0) {
        if ((val & 1) == 0) {
          if (l < r) {
            dep = 0;
            cl = l, cr = r;
            cur = ima;
          }
        } else {
          long long t1 = zero[i] + l - bv[i].rank0(l);
          long long t2 = zero[i] + r - bv[i].rank0(r);
          ima += (1ll << i);
          if (t1 < t2) return ima;
        }
        break;
      }
      if ((val & (1ll << i)) == 0) {
        long long t1 = bv[i].rank0(l);
        long long t2 = bv[i].rank0(r);
        long long s1 = zero[i] + l - t1;
        long long s2 = zero[i] + r - t2;
        if (s1 < s2) {
          dep = i - 1;
          cl = s1, cr = s2;
          cur = ima + (1ll << i);
        }
        l = t1, r = t2;
      } else {
        long long t1 = bv[i].rank0(l);
        long long t2 = bv[i].rank0(r);
        long long s1 = zero[i] + l - t1;
        long long s2 = zero[i] + r - t2;
        l = s1, r = s2;
        ima = ima + (1ll << i);
      }
    }
    if (dep == -1) return -1;
    ima = cur;
    l = cl, r = cr;
    for (long long i = dep; i >= 0; i--) {
      long long t1 = bv[i].rank0(l);
      long long t2 = bv[i].rank0(r);
      if (t2 - t1 == 0) {
        ima += (1ll << i);
        l = zero[i] + l - t1;
        r = zero[i] + r - t2;
      } else {
        l = t1, r = t2;
      }
      assert(l < r);
    }
    return ima;
  }
};
void solve() {
  long long n;
  cin >> n;
  vector<long long> ve(n + 1, 0), rui, rui2;
  for (long long i = 0; i < n; i++) {
    long long y;
    cin >> y;
    ve[y]++;
  }
  rui = ve;
  rui2 = ve;
  rui2[0] = 0;
  for (long long i = 1; i <= n; i++) {
    rui[i] += rui[i - 1];
    rui2[i] *= i;
    rui2[i] += rui2[i - 1];
  }
  long long gr = -1;
  for (long long i = 0; i < n; i++) {
    if (ve[i] == 0) {
      gr = i;
      break;
    }
  }
  vector<long long> ans(n + 1, -1);
  bool dame = 0;
  priority_queue<long long> pq;
  long long p = 0;
  for (long long i = 0; i <= n; i++) {
    if (ve[i] >= 2)
      for (long long j = 0; j < ve[i] - 1; j++) pq.push(i);
    ans[i] = p + ve[i];
    if (pq.size() == 0 && ve[i] == 0) {
      break;
    }
    if (ve[i] == 0) {
      p += i - pq.top();
      pq.pop();
    }
  }
  cout << ans << endl;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n = 1;
  cin >> n;
  for (long long i = 0; i < n; i++) solve();
  return 0;
}
