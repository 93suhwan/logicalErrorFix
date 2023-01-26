#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  out << "{" << a.first << ", " << a.second << "}";
  return out;
}
const int mod = 1e9 + 7;
template <typename T>
void print(T &a) {
  for (auto &x : a) cout << x << " ";
  cout << "\n";
}
const int N = 3e5 + 10;
const int maxn = N;
struct fenwick1 {
  long long A[maxn];
  long long query(int i) {
    long long sum = 0;
    while (i > 0) sum += A[i], i -= ((i) & -(i));
    return sum;
  }
  void update(int i, long long k) {
    if (i < 1) return;
    while (i < maxn) A[i] += k, i += ((i) & -(i));
  }
  void rupd(int l, int r, long long v) {
    update(l, v);
    update(r + 1, -v);
  }
} contribution;
struct fenwick {
  long long A[maxn];
  long long query(int i) {
    long long sum = 0;
    while (i > 0) sum += A[i], i -= ((i) & -(i));
    return sum;
  }
  void update(int i, long long k) {
    if (i < 1) return;
    while (i < maxn) A[i] += k, i += ((i) & -(i));
  }
  long long query(int l, int r) { return (query(r) - query(l - 1)); }
} cnt;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  long long mx = 0;
  for (int i = 0; i < (n); i++) cin >> a[i];
  for (int i = 0; i < (n); i++) amax(mx, a[i]);
  vector<long long> ans(n);
  long long ps = 0;
  long long prev = 0;
  for (int i = 0; i < (n); i++) {
    long long x = a[i];
    long long tmp = a[i] * i;
    tmp -= contribution.query(a[i]);
    long long f = 1;
    while (x * f <= mx) {
      contribution.rupd(x * f, min(x * (f + 1) - 1, mx), x * f);
      f++;
    }
    long long tmp1 = ps;
    long long tmp2 = 0;
    f = 1;
    while (x * f <= mx) {
      tmp2 += f * cnt.query(x * f, min(x * (f + 1) - 1, mx));
      f++;
    }
    tmp1 -= x * tmp2;
    cnt.update(a[i], 1);
    ans[i] = prev + tmp + tmp1;
    prev = ans[i];
    ps += a[i];
  }
  print(ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start1 = high_resolution_clock::now();
  int t = 1;
  while (t--) {
    solve();
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop1 - start1);
  return 0;
}
