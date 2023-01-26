#include <bits/stdc++.h>
using namespace std;
bool findTick(int k, int i, int j, vector<vector<char>> A,
              vector<vector<char>>& B) {
  vector<vector<char>> C = B;
  int sz = 0;
  while (i < A.size() && j < A[0].size() && A[i][j] == '*' && sz != k + 1) {
    C[i][j] = '*';
    sz++;
    i++;
    j++;
  }
  i--;
  j--;
  if (sz - 1 < k) return 0;
  while (i >= 0 && j < A[0].size() && A[i][j] == '*' && sz) {
    C[i][j] = '*';
    sz--;
    i--;
    j++;
  }
  if (sz) return 0;
  B = C;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> A(n, vector<char>(m, '.'));
    vector<vector<char>> B = A;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cin >> A[i][j];
    }
    bool f = 1;
    for (int i = k; i < 20; i++) {
      for (int l = 0; l < n; l++) {
        for (int k = 0; k < m; k++) {
          if (A[l][k] == '*') findTick(i, l, k, A, B);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (A[i][j] == '*' && B[i][j] != '*') f = 0;
      }
    }
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
