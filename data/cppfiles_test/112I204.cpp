#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;
struct CFFast {
  CFFast() { ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); }
} cffast{};
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2>& pair) const {
    return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
  }
};
template <typename T>
void read(T& t) {
  cin >> t;
}
template <typename T>
void read(vector<T>& t) {
  for (auto& v : t) {
    read(v);
  }
}
template <typename T1, typename T2>
void read(vector<pair<T1, T2>>& t) {
  for (auto& v : t) {
    read(v.first);
    read(v.second);
  }
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (const auto& a : v) {
    os << a << " ";
  }
  os << "\n";
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const vector<pair<T1, T2>>& v) {
  for (const auto& a : v) {
    os << "[" << a.first << ", " << a.second << "],";
  }
  os << "\n";
  return os;
}
string solve(ll a, ll b, ll c, ll m) {
  ll pmax = a + b + c - 3;
  ll pmin_a = min(ll(0), (b + c + 1) - a);
  ll pmin_b = min(ll(0), (a + c + 1) - b);
  ll pmin_c = min(ll(0), (b + a + 1) - c);
  ll pmin = pmin_a + pmin_b + pmin_c;
  return (pmax >= m && pmin <= m) ? "YES" : "NO";
}
int main() {
  ll t;
  read(t);
  while (t--) {
    ll a;
    read(a);
    ll b;
    read(b);
    ll c;
    read(c);
    ll m;
    read(m);
    cout << solve(a, b, c, m) << "\n";
  }
}
