#include <bits/stdc++.h>
using namespace std;
template <class A>
void rd(vector<A>& v);
template <class T>
void rd(T& x) {
  cin >> x;
}
template <class H, class... T>
void rd(H& h, T&... t) {
  rd(h);
  rd(t...);
}
template <class A>
void rd(vector<A>& x) {
  for (auto& a : x) rd(a);
}
template <class T>
bool ckmin(T& a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
void __p(T a) {
  cout << a;
}
template <typename T, typename F>
void __p(pair<T, F> a) {
  cout << "{";
  __p(a.first);
  cout << ",";
  __p(a.second);
  cout << "}\n";
}
template <typename T>
void __p(std::vector<T> a) {
  cout << "{";
  for (auto it = a.begin(); it < a.end(); it++)
    __p(*it), cout << ",}\n"[it + 1 == a.end()];
}
template <typename T, typename... Arg>
void __p(T a1, Arg... a) {
  __p(a1);
  __p(a...);
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : ";
  __p(arg1);
  cout << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  int64_t bracket = 0, i = 0;
  for (;; i++)
    if (names[i] == ',' && bracket == 0)
      break;
    else if (names[i] == '(')
      bracket++;
    else if (names[i] == ')')
      bracket--;
  const char* comma = names + i;
  cout.write(names, comma - names) << " : ";
  __p(arg1);
  cout << " | ";
  __f(comma + 1, args...);
}
void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(15);
  cout << fixed;
  if (((int64_t)(s).size())) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}
vector<int64_t> wh[1000 * 1000];
signed main() {
  setIO();
  vector<int64_t> primes;
  for (int64_t x = 2; x <= 1000; ++x) {
    bool ok = true;
    for (int64_t i = 2; i * i <= x; ++i) ok &= x % i != 0;
    if (ok) primes.push_back(x);
  }
  int64_t n;
  rd(n);
  vector<int64_t> a(n);
  rd(a);
  string s;
  rd(s);
  vector<int64_t> f(n, n);
  auto next_smaller = [&](vector<int64_t> b) -> vector<int64_t> {
    vector<int64_t> ret(((int64_t)(b).size()), -1);
    stack<int64_t> st;
    for (int64_t i = 0; i < ((int64_t)(b).size()); ++i) {
      while (!st.empty() && b[st.top()] > b[i]) {
        ret[st.top()] = i;
        st.pop();
      }
      st.push(i);
    }
    return ret;
  };
  for (auto p : primes) {
    vector<int64_t> b = {0};
    for (int64_t i = 0; i < n; ++i) {
      int64_t cnt = 0;
      while (a[i] % p == 0) ++cnt, a[i] /= p;
      b.push_back((s[i] == '*' ? 1 : -1) * cnt);
    }
    for (int64_t i = 1; i < ((int64_t)(b).size()); ++i) b[i] += b[i - 1];
    auto nxt = next_smaller(b);
    for (int64_t i = 0; i < n; ++i) {
      if (nxt[i] > 0) {
        ckmin(f[i], nxt[i] - 1);
      }
    }
  }
  for (int64_t i = 0; i < n; ++i) {
    wh[a[i]].push_back(i);
  }
  for (int64_t x = 1000 + 1; x < 1000 * 1000; ++x) {
    if (((int64_t)(wh[x]).size()) == 0) continue;
    vector<int64_t> b = {0};
    for (auto i : wh[x]) {
      if (s[i] == '*')
        b.push_back(1);
      else
        b.push_back(-1);
    }
    for (int64_t i = 1; i < ((int64_t)(b).size()); ++i) b[i] += b[i - 1];
    auto nxt = next_smaller(b);
    for (int64_t i = 0; i < ((int64_t)(wh[x]).size()); ++i) {
      if (nxt[i] > 0) {
        ckmin(f[wh[x][i]], wh[x][nxt[i] - 1]);
      }
    }
  }
  int64_t out = 0;
  for (int64_t i = 0; i < n; ++i) out += f[i] - i;
  cout << out << "\n";
}
