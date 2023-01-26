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
int n;
pair<pair<int, int>, int> a[100007];
pair<pair<int, int>, int> b[100007];
pair<pair<int, int>, int> c[100007];
pair<pair<int, int>, int> d[100007];
pair<int, int> cnt[100007];
bool ok(pair<pair<int, int>, int>* a, int w1, int w2, int w3, int KEK) {
  int need = KEK;
  int last_x = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i].second == w1) {
      --need;
      last_x = a[i].first.first;
      if (need == 0) break;
    }
  }
  auto LAST = last_x;
  if (need > 0) return 0;
  fill(cnt, cnt + n + 1, make_pair(0, 0));
  for (int i = 0; i < n; ++i) {
    if (a[i].first.first > last_x) {
      if (a[i].second == w2) {
        ++cnt[a[i].first.first].first;
      } else if (a[i].second == w3) {
        ++cnt[a[i].first.first].second;
      }
    }
  }
  need = KEK;
  for (int i = 0; i <= n; ++i) {
    need -= cnt[i].first;
    if (need <= 0) {
      last_x = i;
      break;
    }
  }
  if (need <= 0) {
    need = KEK;
    for (int i = last_x + 1; i <= n; ++i) {
      need -= cnt[i].second;
    }
    if (need <= 0) return 1;
  }
  last_x = LAST;
  fill(cnt, cnt + n + 1, make_pair(0, 0));
  for (int i = 0; i < n; ++i) {
    if (a[i].first.first > last_x) {
      if (a[i].second == w2) {
        ++cnt[a[i].first.second].first;
      } else if (a[i].second == w3) {
        ++cnt[a[i].first.second].second;
      }
    }
  }
  need = KEK;
  for (int i = 0; i <= n; ++i) {
    need -= cnt[i].first;
    if (need <= 0) {
      last_x = i;
      break;
    }
  }
  if (need <= 0) {
    need = KEK;
    for (int i = last_x + 1; i <= n; ++i) {
      need -= cnt[i].second;
    }
    if (need <= 0) return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  readArr(a, a + n);
  vector<int> xx, yy;
  for (int i = 0; i < n; ++i) {
    xx.push_back(a[i].first.first);
    yy.push_back(a[i].first.second);
  }
  sort(xx.begin(), xx.end());
  sort(yy.begin(), yy.end());
  xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
  yy.resize(unique(yy.begin(), yy.end()) - yy.begin());
  for (int i = 0; i < n; ++i) {
    a[i].first.first =
        lower_bound(xx.begin(), xx.end(), a[i].first.first) - xx.begin();
    a[i].first.second =
        lower_bound(yy.begin(), yy.end(), a[i].first.second) - yy.begin();
  }
  for (int i = 0; i < n; ++i) {
    b[i] = a[i];
    swap(b[i].first.first, b[i].first.second);
  }
  for (int i = 0; i < n; ++i) {
    c[i] = a[i];
    c[i].first.first = n - c[i].first.first - 1;
    d[i] = b[i];
    d[i].first.first = n - d[i].first.first - 1;
  }
  sort(a, a + n);
  sort(b, b + n);
  sort(c, c + n);
  sort(d, d + n);
  int vl = 0, vr = n / 3 + 1;
  while (vl + 1 < vr) {
    int vm = (vl + vr) >> 1;
    if (ok(a, 1, 2, 3, vm) || ok(a, 1, 3, 2, vm) || ok(a, 2, 1, 3, vm) ||
        ok(a, 2, 3, 1, vm) || ok(a, 3, 1, 2, vm) || ok(a, 3, 2, 1, vm) ||
        ok(b, 1, 2, 3, vm) || ok(b, 1, 3, 2, vm) || ok(b, 2, 1, 3, vm) ||
        ok(b, 2, 3, 1, vm) || ok(b, 3, 1, 2, vm) || ok(b, 3, 2, 1, vm) ||
        ok(c, 1, 2, 3, vm) || ok(c, 1, 3, 2, vm) || ok(c, 2, 1, 3, vm) ||
        ok(c, 2, 3, 1, vm) || ok(c, 3, 1, 2, vm) || ok(c, 3, 2, 1, vm) ||
        ok(d, 1, 2, 3, vm) || ok(d, 1, 3, 2, vm) || ok(d, 2, 1, 3, vm) ||
        ok(d, 2, 3, 1, vm) || ok(d, 3, 1, 2, vm) || ok(d, 3, 2, 1, vm))
      vl = vm;
    else
      vr = vm;
  }
  cout << vl * 3;
}
