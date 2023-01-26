#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void pr(string x) { cout << '\"' << x << '\"'; }
void pr(char x) { cout << '\'' << x << '\''; }
void pr(long double x) { cout << x; }
void pr(long long x) { cout << x; }
void pr(double x) { cout << x; }
void pr(float x) { cout << x; }
void pr(long x) { cout << x; }
void pr(bool x) { cout << x; }
void pr(int x) { cout << x; }
template <class T, class V>
void pr(const pair<T, V>& x);
template <class T, class V>
void pr(const map<T, V>& mp);
template <class T, class... V>
void pr(T t, V... v);
template <class T>
void pr(const multiset<T>& pq);
template <class T>
void pr(const vector<T>& v);
template <class T>
void pr(const set<T>& pq);
template <class T, class V>
void pr(const pair<T, V>& x) {
  cout << "{";
  pr(x.first);
  cout << ", ";
  pr(x.second);
  cout << "}";
}
template <class T, class V>
void pr(const map<T, V>& mp) {
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    pr(*it);
    auto copy = it;
    if (++copy != mp.end()) cout << " ";
  }
}
template <class T>
void pr(const multiset<T>& pq) {
  vector<T> values;
  for (auto& value : pq) values.push_back(value);
  pr(values);
}
template <class T>
void pr(const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); ++i) {
    pr(v[i]);
    cout << (i + 1 < (int)v.size() ? " " : "");
  }
}
template <class T>
void pr(const set<T>& pq) {
  vector<T> values;
  for (auto value : pq) values.push_back(value);
  pr(values);
}
template <class T, class... V>
void pr(T t, V... v) {
  pr(t);
  if (sizeof...(v)) cout << " | ";
  pr(v...);
}
int MOD;
struct Mint {
  int value;
  Mint(long long v = 0) {
    value = v % MOD;
    if (value < 0) value += MOD;
  }
  Mint(long long a, long long b) : value(0) {
    *this += a;
    *this /= b;
  }
  Mint& operator+=(Mint const& b) {
    value += b.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  Mint& operator-=(Mint const& b) {
    value -= b.value;
    if (value < 0) value += MOD;
    return *this;
  }
  Mint& operator*=(Mint const& b) {
    value = (value * (long long)b.value) % MOD;
    return *this;
  }
  friend Mint power(Mint a, long long e) {
    Mint res = 1;
    while (e > 0) {
      if (e & 1) res *= a;
      a *= a, e /= 2;
    }
    return res;
  }
  friend Mint inverse(Mint a) { return power(a, MOD - 2); }
  Mint& operator/=(Mint const& b) { return *this *= inverse(b); }
  friend Mint operator+(Mint a, Mint const b) { return a += b; }
  friend Mint operator-(Mint a, Mint const b) { return a -= b; }
  friend Mint operator-(Mint a) { return 0 - a; }
  friend Mint operator*(Mint a, Mint const b) { return a *= b; }
  friend Mint operator/(Mint a, Mint const b) { return a /= b; }
  friend ostream& operator<<(ostream& os, Mint const& a) {
    return os << a.value;
  }
  friend bool operator==(Mint const& a, Mint const& b) {
    return a.value == b.value;
  }
  friend bool operator!=(Mint const& a, Mint const& b) {
    return a.value != b.value;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N >> MOD;
  vector<Mint> dp(N + 1), preffix_sum(N + 1);
  dp[1] = preffix_sum[1] = 1;
  for (int i = 2; i <= N; ++i) {
    dp[i] = preffix_sum[i - 1];
    int z = 2;
    while (i / z > 0) {
      int nxt = i / (i / z);
      dp[i] += (nxt - z + 1) * dp[i / z];
      z = nxt + 1;
    }
    preffix_sum[i] = preffix_sum[i - 1] + dp[i];
  }
  cout << dp[N] << '\n';
}
