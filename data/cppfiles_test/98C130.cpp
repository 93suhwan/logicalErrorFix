#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF_INT = 2147483647;
const long INF_L = 1000000000000000003;
const long long INF_LL = 9223372036854775807;
const long double PI = acos((long double)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int ceildiv(int a, int b) { return a / b + !(a < 0 || a % b == 0); }
template <class T>
void read(T &x) {
  cin >> x;
}
void read(double &x) {
  string t;
  read(t);
  x = stod(t);
}
void read(long double &x) {
  string t;
  read(t);
  x = stold(t);
}
template <class T>
void read(complex<T> &x) {
  T a, b;
  read(a, b);
  x = cd(a, b);
}
template <class T1, class T2>
void read(pair<T1, T2> &p) {
  read(p.first, p.second);
}
template <class T>
void read(vector<T> &a) {
  for (int i = 0; i < (int)a.size(); i++) read(a[i]);
}
template <class Arg, class... Args>
void read(Arg &first, Args &...rest) {
  read(first);
  read(rest...);
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
  os << '{' << a.first << ", " << a.second << '}';
  return os;
}
template <class T>
ostream &printArray(ostream &os, const T &a, int SZ) {
  os << '{';
  for (int i = 0; i < SZ; i++) {
    if (i) {
      os << ", ";
    }
    os << a[i];
  }
  os << '}';
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  return printArray(os, a, (int)a.size());
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &a) {
  os << vector<T>(begin(a), end(a));
  return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const map<T1, T2> &a) {
  os << vector<pair<T1, T2>>(begin(a), end(a));
  return os;
}
template <class T>
void pr(const T &x) {
  cout << x << '\n';
}
template <class Arg, class... Args>
void pr(const Arg &first, const Args &...rest) {
  cout << first << ' ';
  pr(rest...);
}
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
void setIO(string S = "", bool use_txt = false) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (!S.empty()) {
    if (use_txt) {
      freopen((S + ".txt").c_str(), "r", stdin);
      freopen((S + ".txt").c_str(), "w", stdout);
    } else {
      freopen((S + ".in").c_str(), "r", stdin);
      freopen((S + ".out").c_str(), "w", stdout);
    }
  }
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
int main() {
  setIO();
  int t;
  string alpha, S;
  read(t);
  while (t--) {
    map<char, int> freq;
    read(alpha, S);
    for (int i = 0; i < 26; i++) freq[alpha[i]] = i;
    int n = (int)S.size(), ans = 0;
    char prev = S[0];
    for (int i = 1; i < n; i++) {
      ans += abs(freq[S[i]] - freq[prev]);
      prev = S[i];
    }
    cout << ans << "\n";
  }
  return 0;
}
