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
const size_t MAX_BIT = 19;
const size_t MAX_SIZE = 1 << MAX_BIT;
struct FenwickTree1 {
  int t[MAX_SIZE];
  int get(int v) {
    int res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      add(res, t[v]);
    }
    return res;
  }
  int get(int vl, int vr) {
    int res = get(vr);
    if (vl > 0) {
      dec(res, get(vl - 1));
    }
    return res;
  }
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      add(t[v], val);
    }
  }
} f;
int n;
pair<int, int> a[400007];
vector<int> ord;
vector<pair<int, int>> zap[400007];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  readArr(a, a + n);
  int sz;
  cin >> sz;
  ord.resize(sz);
  readArr(ord.begin(), ord.end());
  for (int& first : ord) --first;
  int res = 0;
  vector<int> t;
  for (int i = 0; i < n; ++i) t.push_back(i);
  sort(t.begin(), t.end(),
       [](int w1, int w2) { return a[w1].second < a[w2].second; });
  sort(ord.begin(), ord.end(),
       [](int w1, int w2) { return a[w1].second > a[w2].second; });
  int last = 0;
  for (int i = 0; i < ord.size(); ++i) {
    int v = ord[i];
    if (a[v].second < last) break;
    if (a[v].first < last) continue;
    zap[a[v].second].push_back(make_pair(last, a[v].second));
    last = a[v].first;
  }
  for (int v : t) {
    for (auto c : zap[a[v].second]) {
      add(res, 1);
      add(res, f.get(c.first, c.second));
    }
    int val = 1;
    add(val, f.get(a[v].first, 2 * n));
    f.up(a[v].first, val);
  }
  cout << res;
}
