#include <bits/stdc++.h>
using namespace std;
auto M = [](long long x, long long y, int m) { return ((x % m) * y % m) % m; };
template <class T>
inline void read(T &x) {
  char c = getchar();
  x = 0;
  T f = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  x = x * f;
}
template <class T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const long long INF = 2147483647;
const int N = 55;
long long t, n, vis[3];
char res[N][N];
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  vector<int> sec;
  while (t--) {
    cin >> n;
    cin >> s;
    sec.clear();
    vis[1] = 0;
    vis[2] = 0;
    for (auto c : s) {
      vis[c - '0']++;
    }
    if (vis[2] == 1) {
      cout << "NO" << '\n';
      continue;
    }
    for (int i = 0; i <= n - 1; i++) {
      if (s[i] == '2') sec.push_back(i);
    }
    for (int i = 0; i <= (int)sec.size() - 2; i++) {
      res[sec[i]][sec[i + 1]] = '+';
    }
    if (sec.size()) res[sec[(int)sec.size() - 1]][sec[0]] = '+';
    cout << "YES" << '\n';
    for (int i = 0; i <= n - 1; i++) {
      for (int j = 0; j <= n - 1; j++) {
        if (i == j) {
          cout << 'X';
          continue;
        }
        if (res[i][j] == '+') {
          cout << res[i][j];
          continue;
        }
        if (res[j][i] == '+') {
          cout << '-';
          continue;
        }
        cout << '=';
      }
      cout << '\n';
    }
  }
  return 0;
}
