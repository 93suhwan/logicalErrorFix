#include <bits/stdc++.h>
const int N = 100001, M = 998244353, mod = 1000000007;
const long long MX = INT64_MAX, MN = INT64_MIN, oo = 1e18;
using namespace std;
vector<string> tokenizer(string str, char ch) {
  std::istringstream var((str));
  vector<string> v;
  string t;
  while (getline((var), t, (ch))) {
    v.emplace_back(t);
  }
  return v;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\n";
  err(++it, args...);
}
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void put(T&&... args) {
  ((cout << args << " "), ...);
}
void file_i_o() {
  freopen("./tests/test01.txt", "r", stdin);
  freopen("./tests/output01.txt", "w", stdout);
}
void solve(int T) {
  int n, m, k;
  read(n, m, k);
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> grid[i][j];
  while (k--) {
    int c;
    read(c);
    c--;
    int r = 0;
    while (r < n) {
      if (grid[r][c] == 2)
        r++;
      else {
        int nc = c;
        if (grid[r][c] == 1)
          nc++;
        else
          nc--;
        grid[r][c] = 2;
        c = nc;
      }
    }
    put(c + 1);
  }
}
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (int i = 1; i < t + 1; i++) {
    solve(t);
  }
  return 0;
}
