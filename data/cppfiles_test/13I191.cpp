#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 5;
void nxt(char &x) {
  if (x == 'z')
    x = 'a';
  else
    x++;
}
char help(set<char> &st) {
  for (char x = 'a'; x <= 'z'; x++) {
    if (!st.count(x)) {
      st.clear();
      return x;
    }
  }
  return '.';
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<string> mat(n + 2, string(m + 2, '.'));
  auto getc = [&](long long i, long long j, bool hr) {
    set<char> st;
    if (hr) {
      for (long long k = 0; k <= 1; k++)
        st.insert(mat[i - 1][j + k]), st.insert(mat[i + 1][j + k]);
      st.insert(mat[i][j - 1]), st.insert(mat[i][j + 2]);
      return help(st);
    } else {
      for (long long k = 0; k <= 1; k++)
        st.insert(mat[i + k][j - 1]), st.insert(mat[i + k][j + 1]);
      st.insert(mat[i - 1][j]), st.insert(mat[i + 2][j]);
      return help(st);
    }
  };
  if (m & 1) {
    for (long long i = 1; i <= n; i += 2) {
      mat[i][m] = mat[i + 1][m] = getc(i, m, 0);
    }
    m--;
  }
  if (n & 1) {
    for (long long j = 1; j <= m; j += 2) {
      mat[n][j] = mat[n][j + 1] = getc(n, j, 1);
    }
    k -= m / 2;
    n--;
  }
  if (n * m / 2 < k or k & 1 or k < 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (long long i = 1; i <= n; i += 2) {
    for (long long j = 1; j <= m; j += 2) {
      if (k) {
        mat[i][j] = mat[i][j + 1] = getc(i, j, 1);
        mat[i + 1][j] = mat[i + 1][j + 1] = getc(i + 1, j, 1);
        k -= 2;
      } else {
        mat[i][j] = mat[i + 1][j] = getc(i, j, 0);
        mat[i][j + 1] = mat[i + 1][j + 1] = getc(i, j + 1, 0);
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) cout << mat[i][j];
    cout << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long T = 1;
  cin >> T;
  for (long long i = 1; i <= T; i++) {
    solve();
  }
}
string solvegg() {
  long long n, m, k;
  cin >> n >> m >> k;
  m -= m % 2;
  if (n * m / 2 < k) return "NO";
  return "YES";
}
