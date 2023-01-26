#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626433;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long N = 105;
long long n, m, k, p, dp[N][N][N], nCr[N][N];
void func() {
  cin >> n >> m >> k >> p;
  nCr[0][0] = 1;
  for (long long i = 1; i < n + 1; i++) {
    nCr[i][0] = 1;
    for (long long j = 1; j < i + 1; j++)
      nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % p;
  }
  dp[n + 1][0][0] = 1;
  for (long long z = 0; z < k + 1; z++) {
    for (long long j = 0; j < n - z + 1; j++) {
      for (long long i = 1; i < n + 1; i++) {
        if (j == 0 && z == 0)
          dp[i][j][z] = 1;
        else {
          long long z1 = z, j1 = j;
          if (i == m)
            z1--;
          else
            j1--;
          if (z1 < 0 || j1 < 0)
            continue;
          else {
            for (long long j0 = 0; j0 < j1 + 1; j0++) {
              for (long long z0 = 0; z0 < z1 + 1; z0++) {
                if ((!dp[i + 1][j0][z0]) || (!dp[i + 1][j1 - j0][z1 - z0]))
                  continue;
                long long temp =
                    (dp[i + 1][j0][z0] * dp[i + 1][j1 - j0][z1 - z0]) % p;
                temp = (temp * nCr[j1 + z1][j0 + z0]) % p;
                dp[i][j][z] += temp;
                if (dp[i][j][z] >= p) dp[i][j][z] -= p;
              }
            }
          }
        }
      }
    }
  }
  cout << dp[1][n - k][k] << "\n";
}
int main() {
  {
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
  cout << fixed << setprecision(8);
  long long ntc = 1;
  for (long long i = 1; i < ntc + 1; i++) {
    func();
  }
  return 0;
}
