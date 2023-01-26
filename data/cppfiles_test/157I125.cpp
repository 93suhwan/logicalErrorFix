#include <bits/stdc++.h>
using namespace std;
int N, K;
string str;
int ps[5005];
long long ans;
long long C[5005][5005];
void ini() {
  for (int i = 0; i <= N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j <= i - 1; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 998244353;
    }
  }
}
long long cnt(int l, int r) {
  if (ps[r] - ps[l - 1] > K) return 0LL;
  int d = 0;
  if (str[l - 1] == '0')
    d++;
  else
    d--;
  if (str[r - 1] == '0')
    d++;
  else
    d--;
  int I = ps[r - 1] - ps[l] - d;
  int L = r - 1 - l;
  if (I < 0 || I > L) return 0LL;
  return C[L][I];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  cin >> str;
  for (int i = 1; i <= N; i++) {
    ps[i] = (str[i - 1] == '1') ? 1 : 0;
    ps[i] += ps[i - 1];
  }
  ini();
  ans = 1;
  for (int i = 1; i <= N - 1; i++)
    for (int j = i + 1; j <= N; j++) ans = (ans + cnt(i, j)) % 998244353;
  cout << ans << '\n';
  return 0;
}
