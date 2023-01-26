#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vl = vector<long long>;
using pii = pair<int, int>;
char el = '\n';
char esp = ' ';
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
ostream& operator<<(ostream& os, const deque<int>& v) {
  for (auto const& i : v) {
    os << i << " ";
  }
  os << '\n';
  return os;
}
string yes = "YES";
string no = "NO";
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> original(n, vector<char>(m, '.'));
    vector<vector<char>> ans(n, vector<char>(m, '.'));
    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      for (int j = 0; j < m; j++) {
        original[i][j] = s[j];
      }
    }
    auto tri = [&](int ii, int jj) {
      int levels = 0;
      int dif = 0;
      int cur_row = ii;
      while (jj + dif < m && jj - dif > -1 && cur_row > -1 &&
             original[cur_row][jj + dif] == '*' &&
             original[cur_row][jj - dif] == '*') {
        levels++;
        cur_row--;
        dif++;
      }
      if (levels - 1 >= k) {
        dif = 0;
        cur_row = ii;
        while (jj + dif < m && jj - dif > -1 && cur_row > -1 &&
               original[cur_row][jj + dif] == '*' &&
               original[cur_row][jj - dif] == '*') {
          ans[cur_row][jj + dif] = ans[cur_row][jj - dif] = '*';
          cur_row--;
          dif++;
        }
      }
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (original[i][j] == '*') {
          tri(i, j);
        }
      }
    }
    if (original == ans)
      cout << yes << el;
    else
      cout << no << el;
  }
}
