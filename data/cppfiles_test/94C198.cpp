#include <bits/stdc++.h>
using namespace std;
void setIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
const int64_t N = 1e5 + 5;
const int64_t M = 650;
const int64_t inf = 9e12;
const int64_t mod = 998244353;
int64_t xyz = 1;
int64_t n, m;
int64_t arr[N];
int64_t pwr[N];
void run() {
  cin >> n >> m;
  m++;
  pwr[0] = 1;
  for (int64_t i = 1; i <= 12; i++) {
    pwr[i] = pwr[i - 1] * 10;
  }
  for (int64_t i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  arr[n + 1] = 12;
  int64_t num = 0;
  int64_t sum = 0;
  for (int64_t i = 1; i <= n; i++) {
    int64_t add = pwr[arr[i + 1] - arr[i]] - 1;
    if (i == n || sum + add > m) {
      num += (m - sum) * pwr[arr[i]];
      break;
    } else
      sum += add, num += pwr[arr[i]] * add;
  }
  cout << num << "\n";
}
signed main() {
  setIO();
  cin >> xyz;
  while (xyz--) run();
  return 0;
}
