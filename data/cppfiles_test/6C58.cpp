#include <bits/stdc++.h>
using namespace std;
void per() { cerr << endl; }
template <typename Head, typename... Tail>
void per(Head H, Tail... T) {
  cerr << H << ' ';
  per(T...);
}
template <class T>
bool uin(T& a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T& a, T b) {
  return a < b ? (a = b, true) : false;
}
template <class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class U, class V>
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.first >> a.second;
}
template <typename W,
          typename T = typename enable_if<!is_same<W, string>::value,
                                          typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) {
  out << "{ ";
  for (const auto& first : v) out << first << ", ";
  return out << '}';
}
template <class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}
mt19937 mrand(1337);
unsigned int myRand32() { return mrand() & (unsigned int)(-1); }
unsigned long long myRand64() {
  return ((unsigned long long)myRand32() << 32) ^ myRand32();
}
const int mod = 1000000007;
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
void dec(int& a, int b) {
  a -= b;
  if (a < 0) a += mod;
}
int mult(int a, int b) { return a * (long long)b % mod; }
int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}
const int N = 1e5 + 7;
vector<int> divs[N];
int phi[N];
int calc_phi(int n) {
  int result = n;
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  if (n > 1) result -= result / n;
  return result;
}
void init() {
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j * j <= i; ++j) {
      if (i % j == 0) {
        divs[i].push_back(j);
        if (j * j != i) divs[i].push_back(i / j);
      }
    }
    phi[i] = calc_phi(i);
  }
}
int cnt[N];
bool used[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init();
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int res = 0;
  for (int first = 1; first <= n; ++first) {
    for (int pos = first; pos <= n; pos += first) {
      for (int d : divs[a[pos - 1]]) {
        ++cnt[d];
      }
    }
    for (int pos = first; pos <= n; pos += first) {
      for (int d : divs[a[pos - 1]]) {
        if (used[d]) continue;
        used[d] = true;
        int tet = cnt[d];
        int now = mult(phi[first], mult(phi[d], tet * (long long)tet % mod));
        add(res, now);
      }
    }
    for (int pos = first; pos <= n; pos += first) {
      for (int d : divs[a[pos - 1]]) {
        --cnt[d];
        used[d] = false;
      }
    }
  }
  cout << res << "\n";
}
