#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);
struct cmp {
  bool operator()(ll x, ll y) {
    ll origx = x, origy = y;
    if (x == 1 || y == 1) return x == 1;
    while (1) {
      if (x % 10 != 0) break;
      x /= 10;
    }
    while (1) {
      if (y % 10 != 0) break;
      y /= 10;
    }
    if (x == y)
      return origx > origy;
    else
      return x < y;
  }
};
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}\n";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}\n";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "," +
         to_string(get<4>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
void solve() {
  ll s, n;
  cin >> s >> n;
  priority_queue<ll, vector<ll>, cmp> pq;
  ll t = s;
  ll p = 1;
  while (t > 0) {
    if (t % 10 != 0) {
      pq.push(p * (t % 10));
    }
    p *= 10;
    t /= 10;
  }
  if ((int)pq.size() == n) {
    while (!pq.empty()) {
      ll x = pq.top();
      pq.pop();
      cout << x << " ";
    }
    cout << "\n";
    return;
  }
  if ((int)pq.size() > n) {
    int zz = (int)pq.size() - n + 1;
    ll s = 0;
    while (zz--) {
      s += pq.top();
      pq.pop();
    }
    cout << s << " ";
    while (!pq.empty()) {
      cout << pq.top() << " ";
      pq.pop();
    }
    cout << "\n";
    return;
  }
  while ((int)pq.size() != n) {
    ll x = pq.top();
    pq.pop();
    p = 1;
    while (1) {
      if (x % 10 != 0) break;
      x /= 10;
      p *= 10;
    }
    if (x == 1) {
      pq.push(p / 10);
      pq.push(p / 10 * 9);
    } else {
      pq.push(p);
      pq.push(p * (x - 1));
    }
  }
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
