#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
const long long inf = 1e18 + 5;
void fileIO();
template <class T>
void print_container(T &container);
template <class T>
void print_pair_container(T &container);
template <class T>
void printArr(T &a, long long n);
template <typename T>
void debug(string s, T x);
template <typename T, typename... Args>
void debug(string s, T x, Args... args);
long long n, m;
string s;
void solve(long long tc = 0) {
  cin >> n >> s;
  vector<long long> twos;
  for (long long i = 0; i < n; i++) {
    char c = s[i];
    if (c == '2') {
      twos.push_back(i);
    }
  }
  if (twos.size() == 1) {
    cout << "NO\n";
    return;
  }
  if (twos.size() == 2) {
    cout << "NO\n";
    return;
  }
  vector<vector<char>> ans(n, vector<char>(n, '='));
  for (long long i = 0; i < n; i++) {
    ans[i][i] = 'X';
  }
  for (long long i = 0; i < twos.size(); i++) {
    long long next = twos[(i + 1) % twos.size()];
    long long curr = twos[i];
    ans[curr][next] = '+';
    ans[next][curr] = '-';
  }
  cout << "YES\n";
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
}
int32_t main() {
  fileIO();
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve();
  return 0;
}
void fileIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
template <typename T>
void debug(string s, T x) {
  cout << s << " = " << x << "\n";
}
template <typename T, typename... Args>
void debug(string s, T x, Args... args) {
  cout << s.substr(0, s.find(',')) << " = " << x << " | ";
  debug(s.substr(s.find(',') + 2), args...);
}
template <class T>
void print_container(T &container) {
  for (auto &t : container) {
    cout << t << " ";
  }
  cout << "\n";
}
template <class T>
void print_pair_container(T &container) {
  for (auto &t : container) {
    cout << t.first << " " << t.second << "\n";
  }
  cout << "\n";
}
template <class T>
void printArr(T &a, long long n) {
  for (long long i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
