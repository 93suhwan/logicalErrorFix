#include <bits/stdc++.h>
using namespace std;
namespace fft {
struct num {
  long double x, y;
  num() { x = y = 0; }
  num(long double x, long double y) : x(x), y(y) {}
};
inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
inline num operator*(num a, num b) {
  return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
inline num conj(num a) { return num(a.x, -a.y); }
long long base = 1;
vector<num> roots = {{0, 0}, {1, 0}};
vector<long long> rev = {0, 1};
const long double PI = acosl(-1.0);
void ensure_base(long long nbase) {
  if (nbase <= base) {
    return;
  }
  rev.resize(1 << nbase);
  for (long long i = 0; i < (1 << nbase); i++) {
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
  }
  roots.resize(1 << nbase);
  while (base < nbase) {
    long double angle = 2 * PI / (1 << (base + 1));
    for (long long i = 1 << (base - 1); i < (1 << base); i++) {
      roots[i << 1] = roots[i];
      long double angle_i = angle * (2 * i + 1 - (1 << base));
      roots[(i << 1) + 1] =
          num(cos((long double)angle_i), sin((long double)angle_i));
    }
    base++;
  }
}
void fft(vector<num> &a, long long n = -1) {
  if (n == -1) {
    n = a.size();
  }
  assert((n & (n - 1)) == 0);
  long long zeros = __builtin_ctz(n);
  ensure_base(zeros);
  long long shift = base - zeros;
  for (long long i = 0; i < n; i++) {
    if (i < (rev[i] >> shift)) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (long long k = 1; k < n; k <<= 1) {
    for (long long i = 0; i < n; i += 2 * k) {
      for (long long j = 0; j < k; j++) {
        num z = a[i + j + k] * roots[j + k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] = a[i + j] + z;
      }
    }
  }
}
vector<num> fa, fb;
vector<long long> multiply(vector<long long> &a, vector<long long> &b) {
  long long need = a.size() + b.size() - 1;
  long long nbase = 0;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  long long sz = 1 << nbase;
  if (sz > (long long)fa.size()) {
    fa.resize(sz);
  }
  for (long long i = 0; i < sz; i++) {
    long long x = (i < (long long)a.size() ? a[i] : 0);
    long long y = (i < (long long)b.size() ? b[i] : 0);
    fa[i] = num(x, y);
  }
  fft(fa, sz);
  num r(0, -0.25 / sz);
  for (long long i = 0; i <= (sz >> 1); i++) {
    long long j = (sz - i) & (sz - 1);
    num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
    if (i != j) {
      fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
    }
    fa[i] = z;
  }
  fft(fa, sz);
  vector<long long> res(need);
  for (long long i = 0; i < need; i++) {
    res[i] = fa[i].x + 0.5;
  }
  return res;
}
};  // namespace fft
long long n, m, k;
long long pre[200010], suf[200010];
long long v[200010];
long long ris = 0;
long long tot = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  long long som = 0;
  vector<long long> a(k, 0), b(k, 0), c(k, 0);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    som = (som + v[i]) % k;
    c[som]++;
  }
  for (long long i = 0; i < m - 1; i++) tot = (tot + som) % k;
  long long sos = 0;
  for (long long i = 0; i < n; i++) {
    sos = (sos + v[i]) % k;
    ris += pre[sos] + pre[(k - (som + tot) + k) % k];
    if (sos == 0) ris++;
    som = (som - v[i] + k) % k;
    ris %= 1000000007;
    pre[sos]++;
  }
  som = 0;
  for (long long i = n - 1; i >= 0; i--) {
    som = (som + v[i]) % k;
    a[som]++;
  }
  long long kek = 0;
  for (long long i = 0; i < m - 1; i++, kek = (kek + som) % k) {
    b[kek]++;
  }
  if (k <= 1000) {
    vector<long long> pro(k * 2, 0);
    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++)
        pro[i + j] = (pro[i + j] + a[i] * b[j]) % 1000000007;
    a = pro;
    for (long long i = 0; i < k; i++) {
      for (long long j = i + k; j < (long long)a.size(); j += k) a[i] += a[j];
    }
    a.resize(k);
    pro = vector<long long>(k * 2, 0);
    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++)
        pro[i + j] = (pro[i + j] + a[i] * c[j]) % 1000000007;
    a = pro;
  } else {
    if (som != 0) {
      a = fft::multiply(a, b);
      for (long long i = 0; i < k; i++) {
        for (long long j = i + k; j < (long long)a.size(); j += k) a[i] += a[j];
      }
      a.resize(k);
      for (long long i = 0; i < (long long)a.size(); i++) a[i] %= 1000000007;
      a = fft::multiply(a, c);
    } else {
      for (int i = 0; i < k; i++) a[i] = (a[i] * b[0]) % 1000000007;
      a = fft::multiply(a, c);
    }
  }
  for (long long i = 0; i < (long long)a.size(); i += k) {
    ris = (ris + a[i]) % 1000000007;
  }
  cout << ((ris * m) % 1000000007 -
           ((tot + som) % k == 0 ? n * m - 1 : 0) % 1000000007 + 1000000007) %
              1000000007
       << "\n";
}
