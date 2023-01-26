#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long ans[510][510];
long long c[510][510], pangkat[510][510];
void calc() {
  for (int i = 0; i < 510; i++) {
    c[i][0] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    c[i][i] = 1;
    pangkat[i][0] = 1;
    for (int j = 1; j < 510; j++) {
      pangkat[i][j] = i * pangkat[i][j - 1] % mod;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  calc();
  for (int i = 1; i <= 500; i++) {
    ans[1][i] = 0;
  }
  for (int i = 2; i <= 500; i++) {
    for (int j = 1; j <= 500; j++) {
      ans[i][j] = pangkat[min(i - 1, j)][i];
      if (j >= i) {
        for (int k = 0; k < i; k++) {
          ans[i][j] +=
              ans[i - k][j - i + 1] * c[i][k] % mod * pangkat[i - 1][k] % mod;
          ans[i][j] %= mod;
        }
      }
    }
  }
  int n, x;
  cin >> n >> x;
  cout << ans[n][x] << endl;
}
