#include <bits/stdc++.h>
using namespace std;
ifstream fin("file.in");
ofstream fout("file.out");
const int N = 105;
const int K = 2;
int T, n, v[K][N], a[K][N];
char r;
void Read() {
  cin >> n;
  for (int i = 0; i < K; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> r;
      v[i][j] = r - '0';
      a[i][j] = 0;
    }
  }
}
string Solve() {
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      if (!v[0][1]) {
        a[0][1] = 1;
        if (!v[1][1]) a[1][1] = 1;
      }
    } else {
      if (!v[0][i] &&
          ((!v[0][i - 1] && a[0][i - 1]) || (!v[1][i - 1] && a[1][i - 1])))
        a[0][i] = 1;
      if (!v[1][i] &&
          ((!v[0][i - 1] && a[0][i - 1]) || (!v[1][i - 1] && a[1][i - 1])))
        a[1][i] = 1;
    }
  }
  if (a[1][n]) return "YES";
  return "NO";
}
int main() {
  cin >> T;
  while (T--) {
    Read();
    cout << Solve() << '\n';
  }
}
