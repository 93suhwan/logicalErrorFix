#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
#pragma warning(disable : 4996)
using namespace std;
template <typename T>
void print(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
  cout << "\n";
}
template <typename T>
void print(deque<T>& a) {
  for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
  cout << "\n";
}
template <typename T>
void print(vector<vector<T>>& a) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) cout << a[i][j];
    cout << "\n";
  }
}
template <typename T>
void input(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) cin >> a[i];
}
template <typename T>
void input(deque<T>& a) {
  for (int i = 0; i < a.size(); i++) cin >> a[i];
}
template <typename T>
void input(vector<vector<T>>& a) {
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a[i].size(); j++) cin >> a[i][j];
}
const long long INF = 1e9 + 5;
const long long MOD = 1000000007;
const int NMAX = 1e5 + 1337;
double EPS = 1e-10;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int dx = 0, dy = 0;
  int cnt = 0;
  int most_x_l, most_x_r;
  int most_y_u, most_y_d;
  most_x_l = most_x_r = most_y_u = most_y_d = 0;
  for (char c : s) {
    if (c == 'U')
      dy++;
    else if (c == 'D')
      dy--;
    else if (c == 'L')
      dx--;
    else
      dx++;
    if (dx < 0) most_x_l = max(most_x_l, abs(dx));
    if (dx > 0) most_x_r = max(most_x_r, abs(dx));
    if (dy > 0) most_y_u = max(most_y_u, abs(dy));
    if (dy < 0) most_y_d = max(most_y_d, abs(dy));
    int len_y = most_y_u + most_y_d + 1;
    int len_x = most_x_r + most_x_l + 1;
    if (len_y > n || len_x > m) break;
    cnt++;
  }
  most_x_l = most_x_r = most_y_u = most_y_d = 0;
  dx = dy = 0;
  for (int i = 0; i < cnt; i++) {
    char c = s[i];
    if (c == 'U')
      dy++;
    else if (c == 'D')
      dy--;
    else if (c == 'L')
      dx--;
    else
      dx++;
    if (dx < 0) most_x_l = max(most_x_l, abs(dx));
    if (dx > 0) most_x_r = max(most_x_r, abs(dx));
    if (dy > 0) most_y_u = max(most_y_u, abs(dy));
    if (dy < 0) most_y_d = max(most_y_d, abs(dy));
  }
  cout << most_y_u + 1 << " " << most_x_l + 1 << "\n";
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(12);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
