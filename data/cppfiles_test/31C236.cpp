#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
long long read() {
  long long x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x;
}
template <typename T>
inline void rmqmin(T f[][20], T n) {
  for (int i = 1; i <= n; i++) cin >> f[i][0];
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++)
      if (i + (1 << j) - 1 <= n)
        f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}
template <typename T>
inline T zymin(T f[][20], T z, T y) {
  int x = int(log(y - z + 1) / log(2));
  return min(f[z][x], f[y - (1 << x) + 1][x]);
}
template <typename T>
inline void rmqmax(T f[][20], T n) {
  for (int i = 1; i <= n; i++) cin >> f[i][0];
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++)
      if (i + (1 << j) - 1 <= n)
        f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}
template <typename T>
inline T zymax(T f[][20], T z, T y) {
  int x = int(log(y - z + 1) / log(2));
  return max(f[z][x], f[y - (1 << x) + 1][x]);
}
template <typename T>
inline void stgcd(T f[][20], T n) {
  for (int i = 1; i <= n; i++) cin >> f[i][0], f[i + n][0] = f[i][0];
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i + (1 << j) - 1 <= 2 * n; i++) {
      f[i][j] = __gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
}
template <typename T>
inline T qgcd(T f[][20], T z, T y) {
  int x = int(log(y - z + 1) / log(2));
  return __gcd(f[z][x], f[y - (1 << x) + 1][x]);
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int mod = 998244353;
int arr[1000005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    if (n % 2 == 0) {
      for (int i = 1; i <= n / 2; i++) cout << -arr[n - i + 1] << " ";
      for (int i = n / 2 + 1; i <= n; i++) cout << arr[n - i + 1] << " ";
      cout << endl;
    } else {
      if (arr[1] + arr[2] != 0)
        cout << -arr[3] << " " << -arr[3] << " " << arr[1] + arr[2] << " ";
      else if (arr[1] + arr[3] != 0)
        cout << -arr[2] << " " << arr[1] + arr[3] << " " << -arr[2] << " ";
      else if (arr[2] + arr[3] != 0)
        cout << arr[2] + arr[3] << " " << -arr[1] << " " << -arr[1] << " ";
      for (int i = 4; i <= (n - 3) / 2 + 3; i++) cout << -arr[n - i + 4] << " ";
      for (int i = (n - 3) / 2 + 4; i <= n; i++) cout << arr[n - i + 4] << " ";
      cout << endl;
    }
  }
}
