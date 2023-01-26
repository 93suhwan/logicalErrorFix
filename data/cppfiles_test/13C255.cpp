#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b) {
  long long res = 1;
  if (a >= 1000000007) a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= 1000000007) res %= 1000000007;
    a = a * a;
    if (a >= 1000000007) a %= 1000000007;
  }
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int table[102][102];
char dominos[102][102];
map<int, char> M;
int n, m;
char get_new_char(int i, int j) {
  int x = table[i][j];
  set<int> S;
  for (int r = max(0, i - 2); r < min(n, i + 3); r++) {
    for (int c = max(0, j - 2); c < min(m, j + 3); c++) {
      S.insert(table[r][c]);
    }
  }
  for (char ans = 'a'; ans <= 'z'; ans++) {
    bool flag = true;
    for (auto z : S) {
      if (M.find(z) != M.end()) {
        if (M[z] == ans) {
          flag = false;
          break;
        }
      }
    }
    if (flag) return ans;
  }
  return 'z';
}
void printTable() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << table[i][j];
    cout << endl;
  }
  cout << "---------------------------------\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    M.clear();
    int k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) table[i][j] = -1;
    int needed = 0;
    int d = 0;
    int N = n;
    if (N % 2) {
      needed += m / 2;
      N--;
      for (int i = 0; i < m; i += 2) {
        table[0][i] = d;
        table[0][i + 1] = d;
        d++;
      }
    }
    int col_count = 0;
    bool flag = true;
    int r = (n % 2);
    int c = 0;
    while (N > 0 && needed < k) {
      if ((col_count + 1) > (m / 2)) {
        flag = false;
        break;
      }
      table[r][c] = d;
      table[r][c + 1] = d;
      d++;
      table[r + 1][c] = d;
      table[r + 1][c + 1] = d;
      d++;
      c += 2;
      needed += 2;
      col_count++;
      if (col_count == (m / 2)) {
        N -= 2;
        col_count = 0;
        r += 2;
        c = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (table[i][j] == -1) {
          table[i][j] = d;
          table[i + 1][j] = d;
          d++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (M.find(table[i][j]) == M.end()) {
          M[table[i][j]] = get_new_char(i, j);
        }
        dominos[i][j] = M[table[i][j]];
      }
    }
    if (needed != k || !flag) {
      cout << "NO" << endl;
      continue;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << dominos[i][j];
        cout << endl;
      }
    }
  }
  return 0;
}
