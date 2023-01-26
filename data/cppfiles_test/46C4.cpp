#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using ull = unsigned long long;
using int2 = pair<ll, ll>;
using int3 = tuple<ll, ll, ll>;
template <typename A>
string to_string(const A &v);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(const pair<A, B> &p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(const tuple<A, B, C> &p) {
  return "(" + to_string(std::get<0>(p)) + ", " + to_string(std::get<1>(p)) +
         ", " + to_string(std::get<2>(p)) + ")";
}
template <size_t V>
string to_string(const bitset<V> &v) {
  return v.to_string();
}
template <typename A>
string to_string(const A &v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A>
string to_string(const priority_queue<A, vector<A>, greater<A>> &v) {
  priority_queue<A, vector<A>, greater<A>> q = v;
  string res = "[";
  while (!q.empty()) {
    res += to_string(q.top()) + ", ";
    q.pop();
  }
  res += "]";
  return res;
}
template <typename T>
void sort(vector<T> &val) {
  sort(val.begin(), val.end());
}
template <typename T>
void reverse(vector<T> &val) {
  reverse(val.begin(), val.end());
}
template <typename T>
void reverse(map<T, T> &val) {
  reverse(val.begin(), val.end());
}
template <typename T>
void sort_b(vector<T> &val) {
  sort(val.begin(), val.end(), greater<T>());
}
template <typename T>
T pair_sum(pair<T, T> &val) {
  return val.first + val.second;
}
template <typename T>
T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <typename T>
T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <typename T>
T mul_mod(T a, T b, T mod) {
  T res = 0;
  a %= mod;
  while (b) {
    if (b & 1) {
      res = (res + a) % mod;
    }
    a = (2 * a) % mod;
    b >>= 1;
  }
  return res;
}
template <typename T>
T fac_mod(T v, T mod) {
  ll res = 1;
  for (ll i = 1; i <= v; i++) {
    res *= i;
    res = res % mod;
  }
  return res;
}
template <typename T>
T pow_mod(T v, T p, T mod) {
  if (p == 1) return v;
  if (p % 2 == 0) {
    T t = pow_mod(v, p / 2, mod);
    return (t * t) % mod;
  } else {
    return (v * pow_mod(v, p - 1, mod)) % mod;
  }
}
template <typename T>
T gcd_ext(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = gcd_ext(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return d;
}
void cinv(vll &a) {
  for (ll &v : a) {
    cin >> v;
  }
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
class mytask {
 public:
  mytask() {}
  int solve() {
    ll n;
    cin >> n;
    vll a(n);
    cinv(a);
    vll b(n);
    ll res = 0;
    for (ll i = 0; i < n - 1; i += 2) {
      res += min(a[i], a[i + 1]);
      b[i / 2] = a[i] - a[i + 1];
    }
    for (ll i = 0; i < n / 2; i++) {
      ll opens = b[i];
      ll opens_next = 0;
      for (ll j = i + 1; j < n / 2; j++) {
        if (opens < 0) {
          break;
        }
        if (b[j] > 0) {
          opens_next += b[j];
        } else {
          ll bj = -b[j];
          ll dif = min(bj, opens_next);
          opens_next -= dif;
          bj -= dif;
          if (opens_next == 0) {
            res++;
            res += min(opens, bj);
            opens -= bj;
          }
        }
      }
    };
    ;
    cout << res;
    return 0;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  auto task = mytask();
  task.solve();
  return 0;
}
