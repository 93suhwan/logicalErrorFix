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
struct Seg {
  pair<int, int> p;
  int index;
};
const int MAX_SIZE = 400007;
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
    if (vl > vr) return 0;
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
};
FenwickTree1 f;
bool cmp2(Seg& a, Seg& b) { return (a.p < b.p); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Seg> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].p.first >> v[i].p.second;
    v[i].index = i;
  }
  vector<bool> need(n, false);
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int first;
    cin >> first;
    need[first - 1] = true;
  }
  vector<int> steps(n);
  sort(v.begin(), v.end(), cmp2);
  for (int i = n - 1; i >= 0; --i) {
    int S = f.get(v[i].p.first, v[i].p.second);
    add(S, 1);
    steps[v[i].index] = S;
    f.up(v[i].p.second, S);
  }
  int mx = -1;
  for (auto first : v) {
    if (need[first.index]) {
      mx = max(mx, first.p.second);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i].p.second <= mx) {
      add(ans, steps[v[i].index]);
      if (need[v[i].index]) {
        k--;
        if (k == 0) {
          cout << ans;
          exit(0);
        }
      }
    }
  }
}
