#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B, typename C>
struct triple {
  A X;
  B Y;
  C Z;
  triple(A a = 0, B b = 0, C c = 0) : X(a), Y(b), Z(c) {}
};
template <typename A, typename B, typename C>
triple<A, B, C> make_triple(A a = 0, B b = 0, C c = 0) {
  return triple<A, B, C>(a, b, c);
}
template <typename A, typename B, typename C>
bool operator<(const triple<A, B, C>& a, const triple<A, B, C>& b) {
  if (a.X != b.X) return a.X < b.X;
  if (a.Y != b.Y) return a.Y < b.Y;
  return a.Z < b.Z;
}
template <typename T, typename SS>
ostream& operator<<(ostream& ofs, const pair<T, SS>& p) {
  ofs << "( " << p.first << " , " << p.second << " )";
  return ofs;
}
template <typename T>
void print(T a) {
  for (auto i : a) cout << i << ' ';
  cout << '\n';
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T, typename D>
D min(T a) {
  return *min_element(a.begin(), a.end());
}
template <typename T, typename D>
D max(T a) {
  return *max_element(a.begin(), a.end());
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
vector<long long> a;
long long cnt(long long l, long long r) {
  if (r - l <= 0) return 0;
  long long m = l + r >> 1;
  long long ret = cnt(l, m) + cnt(m + 1, r);
  vector<long long> lft, rgt;
  for (long long i = l; i <= m; i++) lft.push_back(a[i]);
  for (long long i = m + 1; i <= r; i++) rgt.push_back(a[i]);
  long long cur = l;
  long long i = 0, j = 0;
  while (i < (long long)(lft.size()) && j < (long long)(rgt.size())) {
    if (lft[i] <= rgt[j])
      a[cur++] = lft[i++];
    else {
      ret += (long long)(lft.size()) - i;
      a[cur++] = rgt[j++];
    }
  }
  while (i < (long long)(lft.size())) a[cur++] = lft[i++];
  while (j < (long long)(rgt.size())) a[cur++] = rgt[j++];
  return ret;
}
void solve() {
  long long n;
  cin >> n;
  a.assign(n, 0);
  for (long long i = 0; i < (n); i++) cin >> a[i];
  long long x = cnt(0, n - 1);
  cout << x << '\n';
  if (x & 1)
    cout << "NO\n";
  else
    cout << "YES\n";
};
signed main() {
  if (0) {
    freopen(
        "che"
        ".in",
        "r", stdin);
    freopen(
        "che"
        ".out",
        "w", stdout);
  }
  srand(time(NULL));
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long t = 1;
  cin >> t;
  for (long long _ = 0; _ < (t); _++) solve();
}
