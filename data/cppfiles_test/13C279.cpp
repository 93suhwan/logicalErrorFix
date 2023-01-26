#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vc = vector<char>;
using vd = vector<double>;
using pii = pair<int, int>;
using pss = pair<string, string>;
using ll = long long;
using tup = tuple<ll, int, int>;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
template <typename Os, class V>
Os& operator<<(Os& os, V const& v) {
  for (auto const& e : v) os << e << " ";
  return os;
}
char table[102][102];
char getColor(int r, int c, bool vert) {
  char ans;
  if (vert) {
    for (int i = (0); i < (26); ++i) {
      ans = 'a' + i;
      if ((c > 0 && (table[r][c - 1] == ans || table[r - 1][c - 1] == ans)) ||
          table[r + 1][c] == ans)
        continue;
      else
        break;
    }
  } else {
    for (int i = (0); i < (26); ++i) {
      ans = 'a' + i;
      if ((c > 0 && table[r][c - 1] == ans) || table[r + 1][c] == ans)
        continue;
      else
        break;
    }
  }
  return ans;
}
void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  memset(table, 0, sizeof table);
  if (K && M == 1) {
    cout << "NO"
         << "\n";
    return;
  }
  int kPerRow = (M / 2);
  int leftN = N, leftK = K;
  if (N % 2 == 1) {
    if (kPerRow > K) {
      cout << "NO"
           << "\n";
      return;
    }
    char chr = 'a';
    for (int c = 0; c < M - 1; c += 2) {
      table[leftN - 1][c] = table[leftN - 1][c + 1] = chr;
      chr++;
      if (chr == 'z' + 1) chr = 'a';
    }
    leftK = K - kPerRow;
    leftN--;
  }
  if (leftK % 2 == 1 || kPerRow * leftN < leftK) {
    cout << "NO"
         << "\n";
    return;
  }
  int row = leftN - 1, col = 0;
  while (col < M - 1 && leftK) {
    while (row >= 0 && leftK) {
      char chr = getColor(row, col, false);
      table[row][col] = chr;
      table[row][col + 1] = chr;
      row--, leftK--;
    }
    if (row < 0) col += 2, row = leftN - 1;
  }
  while (col < M) {
    while (row > 0) {
      if (table[row][col] == 0) {
        char chr = getColor(row, col, true);
        table[row][col] = chr;
        table[row - 1][col] = chr;
      }
      row -= 2;
    }
    col++;
    row = leftN - 1;
  }
  cout << "YES"
       << "\n";
  for (int r = (0); r < (N); ++r) {
    for (int c = (0); c < (M); ++c) cout << table[r][c];
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int TC = (0); TC < (T); ++TC) {
    solve();
  }
}
