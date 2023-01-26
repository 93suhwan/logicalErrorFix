#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long output[11][20];
long long input[11][20];
char inpu[11][22];
void solve() {
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cin >> inpu[i][j];
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (inpu[i][j] == '*')
        input[i][j] = 1;
      else
        input[i][j] = -1;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      output[i][j] = 2;
    }
  }
  for (long long i = n - 1; i >= k; i--) {
    for (long long j = k; j < m - k; j++) {
      if (input[i][j] == 1) {
        if (output[i][j] == 2) {
          output[i][j] = 1;
          long long q1, q2, q3;
          q1 = i - 1;
          q2 = j - 1;
          q3 = j + 1;
          for (long long q = 0; q < k; q++) {
            output[q1][q2] = 1;
            output[q1][q3] = 1;
            q1--;
            q2--;
            q3++;
          }
          while (q1 >= 0 && q2 >= 0 && q3 < m) {
            if (input[q1][q2] == 1 && input[q1][q3] == 1) {
              output[q1][q2] = 1;
              output[q1][q3] = 1;
              q1--;
              q2--;
              q3++;
            } else
              break;
          }
        } else {
          long long q1, q2, q3;
          q1 = i - 1;
          q2 = j - 1;
          q3 = j + 1;
          for (long long q = 0; q < k; q++) {
            if (input[q1][q2] == 1 && input[q1][q3] == 1) {
              output[q1][q2] = 0;
              output[q1][q3] = 0;
              q1--;
              q2--;
              q3++;
            } else
              break;
          }
          while (q1 >= 0 && q2 >= 0 && q3 < m) {
            if (input[q1][q2] == 1 && input[q1][q3] == 1) {
              output[q1][q2] = 0;
              output[q1][q3] = 0;
              q1--;
              q2--;
              q3++;
            } else
              break;
          }
        }
      }
    }
  }
  bool check = 1;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (input[i][j] == -1 && output[i][j] == 1) {
        check = 0;
        break;
      } else if (input[i][j] == 1 && output[i][j] == 2) {
        check = 0;
        break;
      }
    }
  }
  if (check == 0)
    cout << "NO" << '\n';
  else
    cout << "YES" << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
