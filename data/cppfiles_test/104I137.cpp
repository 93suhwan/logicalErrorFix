#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
inline ll popcnt(ull a) { return __builtin_popcountll(a); }
ll intpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b /= 2;
  }
  return ans;
}
ll intpow(ll a, ll b, ll m) {
  ll ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= m;
    (a *= a) %= m;
    b /= 2;
  }
  return ans;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
void scan(T& a) {
  cin >> a;
}
template <class T>
void scan(vector<T>& a) {
  for (auto&& i : a) scan(i);
}
void in() {}
template <class Head, class... Tail>
void in(Head& head, Tail&... tail) {
  scan(head);
  in(tail...);
}
void print() { cout << ' '; }
template <class T>
void print(const T& a) {
  cout << a;
}
template <class T>
void print(const vector<T>& a) {
  if (a.empty()) return;
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    cout << ' ';
    print(*i);
  }
}
int out() {
  cout << '\n';
  return 0;
}
template <class T>
int out(const T& t) {
  print(t);
  cout << '\n';
  return 0;
}
template <class Head, class... Tail>
int out(const Head& head, const Tail&... tail) {
  print(head);
  cout << ' ';
  out(tail...);
  return 0;
}
void solve() {
  long long n;
  in(n);
  vector<long long> a(n);
  in(a);
  vc<long long> ans;
  auto f = [&](long long i) -> void {
    assert(i >= 0 and i < n);
    ans.push_back(i);
    long long x = (a[i] ^ a[i + 1] ^ a[i + 2]);
    a[i] = x;
    a[i + 1] = x;
    a[i + 2] = x;
  };
  long long zcnt = 0, ocnt = 0;
  for (long long i = 0; i < n; ++i) {
    if (a[i] == 0)
      ++zcnt;
    else
      ++ocnt;
  }
  if (ocnt % 2 == 1) {
    out("NO");
    return;
  };
  long long cnt = 0;
  for (long long i = 0; i < n; ++i) {
    if (a[i] == 0) {
      if (cnt % 2 == 0) {
        cnt = 0;
      } else {
        if (i + 1 < n) {
          f(i - 1);
          if (a[i] == 0) {
            cnt = 0;
          } else {
            ++cnt;
          }
        }
      }
    } else {
      ++cnt;
    }
  };
  for (long long i = 0; i < n; ++i) {
    if (i - 1 >= 0 and a[i - 1] == 1 and a[i] == 0) {
      for (long long j = i - 2; j >= 0 and a[j] == 1; j -= 2) {
        f(j);
      }
    }
    if (i + 1 < n and a[i] == 0 and a[i + 1] == 1) {
      for (long long j = i; j + 2 < n and a[j + 2] == 1; j += 2) {
        f(j);
      }
    }
  };
  for (long long i = 0; i < n; ++i) {
    if (a[i] == 1) {
      out("NO");
      return;
    }
  }
  out("YES");
  for (long long& x : ans) ++x;
  out((long long)(ans).size());
  out(ans);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  in(t);
  for (long long i = 0; i < t; ++i) solve();
  return 0;
}
