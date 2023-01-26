#include <bits/stdc++.h>
using namespace std;
void print(vector<pair<long long, long long> > &v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
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
void v_sort(vector<long long> &v) { sort(v.begin(), v.end()); }
void print(vector<long long> v) {
  for (long long i = 0; i < (long long)v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void print(vector<vector<long long> > &v) {
  for (long long i = 0; i < (long long)v.size(); i++) {
    print(v[i]);
  }
}
void Array(long long n, vector<long long> &v) {
  v.clear();
  v.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
}
void Array_1(long long n, vector<long long> &v) {
  v.clear();
  v.resize(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> v[i];
  }
}
void tree_edges(long long n, vector<vector<long long> > &adj) {
  adj.resize(n + 1);
  for (long long i = 0; i < n - 1; i++) {
    long long a;
    long long b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}
void Matrix(long long n, long long m, vector<vector<long long> > &v,
            long long second = 0) {
  v.resize(n);
  for (long long i = 0; i < n; i++) {
    v[i].resize(m);
    for (long long j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
}
void here(long long i = 0) { cout << "here " << i << endl; }
bool is_odd(long long n) { return n % 2; }
bool is_even(long long n) { return !is_odd(n); }
long long nc2(long long n) {
  if (n == 1) return 0;
  if (is_even(n)) {
    return (n / 2) * (n - 1);
  }
  return ((n - 1) / 2) * n;
}
void ans(long long test) { cout << "Case #" << test << ": "; }
void print(vector<string> v) {
  for (long long i = 0; i < (long long)v.size(); i++) {
    cout << v[i] << endl;
  }
}
void solve() {
  string s1, s2;
  long long p1, p2;
  cin >> s1 >> p1 >> s2 >> p2;
  if ((long long)s1.length() + p1 > (long long)s2.length() + p2) {
    cout << ">" << endl;
    return;
  }
  if ((long long)s1.length() + p1 < (long long)s2.length() + p2) {
    cout << "<" << endl;
    return;
  }
  while ((long long)s1.length() < (long long)s2.length()) {
    s1.push_back('0');
  }
  while ((long long)s2.length() < (long long)s1.length()) {
    s2.push_back('0');
  }
  for (long long i = 0; i < s1.length(); i++) {
    if (s1[i] < s2[i]) {
      cout << "<" << endl;
      return;
    } else if (s2[i] < s1[i]) {
      cout << ">" << endl;
      return;
    }
  }
  cout << "=" << endl;
  return;
}
signed main() {
  long long t = 1;
  cin >> t;
  cout << fixed << setprecision(15);
  long long test = 1;
  while (t--) {
    solve();
    test++;
  }
}
