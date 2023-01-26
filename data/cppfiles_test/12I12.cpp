#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (int i = 0; i < (int)vec.size(); i++) {
    os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
  }
  os << "}";
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
  os << "{";
  for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
    os << "(" << itr->first << ", " << itr->second << ")";
    itr++;
    if (itr != map_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
  os << "{";
  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
    os << (*itr);
    ++itr;
    if (itr != set_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S>
void scan(pair<T, S> &p) {
  scan(p.first), scan(p.second);
}
template <class T>
void scan(vector<T> &);
template <class T>
void scan(vector<T> &a) {
  for (auto &i : a) scan(i);
}
template <class T>
void scan(T &a) {
  cin >> a;
}
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &...tail) {
  scan(head);
  IN(tail...);
}
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
  std::fill((T *)array, (T *)(array + N), val);
}
template <class T>
T ceil(T x, T y) {
  assert(y >= 1);
  return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T>
T floor(T x, T y) {
  assert(y >= 1);
  return (x > 0 ? x / y : (x + y - 1) / y);
}
vector<int> iota(int n) {
  vector<int> a(n);
  iota((a).begin(), (a).end(), 0);
  return a;
}
template <class T>
T POW(T x, int n) {
  T res = 1;
  for (; n; n >>= 1, x *= x) {
    if (n & 1) res *= x;
  }
  return res;
}
long long pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
long long allbit(long long n) { return (1LL << n) - 1; }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
template <class S>
void fold_in(vector<S> &v) {}
template <typename Head, typename... Tail, class S>
void fold_in(vector<S> &v, Head &&a, Tail &&...tail) {
  for (auto e : a) v.emplace_back(e);
  fold_in(v, tail...);
}
template <class S>
void renumber(vector<S> &v) {}
template <typename Head, typename... Tail, class S>
void renumber(vector<S> &v, Head &&a, Tail &&...tail) {
  for (auto &&e : a)
    e = distance((v).begin(), lower_bound((v).begin(), (v).end(), (e)));
  renumber(v, tail...);
}
template <class S, class... Args>
void zip(vector<S> &head, Args &&...args) {
  vector<S> v;
  fold_in(v, head, args...);
  sort((v).begin(), (v).end()),
      v.erase(unique((v).begin(), (v).end()), v.end());
  renumber(v, head, args...);
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
pair<long long, long long> d[2020][2020];
pair<long long, long long> u[2020][2020];
int main() {
  int n, m;
  IN(n, m);
  n++;
  m++;
  vector<string> s(n);
  IN(s);
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(m); ++j) {
      d[i][j] = make_pair(-10000, -10000);
      u[i][j] = make_pair(10000, 10000);
    }
  }
  auto dist = [&](pair<long long, long long> a, long long x,
                  long long y) -> long long {
    (void(0));
    return (x - a.first) * (x - a.first) + (y - a.second) * (y - a.second);
  };
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(m); ++j) {
      if (s[i][j] == '1') {
        d[i][j] = make_pair(i, j);
      } else {
        if (i != 0) {
          d[i][j] = d[i - 1][j];
        }
      }
    }
    for (int j = 0; j < (int)(m - 1); ++j) {
      if (dist(d[i][j], i, j + 1) < dist(d[i][j + 1], i, j + 1)) {
        d[i][j + 1] = d[i][j];
      }
    }
    for (int j = (int)m - 1; j >= 0; --j) {
      if (j == 0) continue;
      if (dist(d[i][j], i, j - 1) < dist(d[i][j - 1], i, j - 1)) {
        d[i][j - 1] = d[i][j];
      }
    }
    for (int j = 0; j < (int)(m); ++j) {
      (void(0));
    }
  }
  for (int i = (int)n - 1; i >= 0; --i) {
    for (int j = 0; j < (int)(m); ++j) {
      if (s[i][j] == '1') {
        u[i][j] = make_pair(i, j);
      } else {
        if (i != n - 1) {
          u[i][j] = u[i + 1][j];
        }
      }
    }
    for (int j = 0; j < (int)(m - 1); ++j) {
      if (dist(u[i][j], i, j + 1) < dist(u[i][j + 1], i, j + 1)) {
        u[i][j + 1] = u[i][j];
      }
    }
    for (int j = (int)m - 1; j >= 0; --j) {
      if (j == 0) continue;
      if (dist(u[i][j], i, j - 1) < dist(u[i][j - 1], i, j - 1)) {
        u[i][j - 1] = u[i][j];
      }
    }
  }
  long long res = 0;
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(m); ++j) {
      (void(0));
      res += min(dist(d[i][j], i, j), dist(u[i][j], i, j));
    }
  }
  cout << res << endl;
  return 0;
}
