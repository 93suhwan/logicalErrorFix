#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int inf = 998244353;
int n;
long long a[N], b[N], k[N];
long long get(long long a, long long b) {
  if (a <= b) return 0;
  if (a % b == 0) return a / b - 1;
  return a / b;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  long long sum = 0, ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    k[i] = get(a[i], b[i + 1]);
    b[i] = a[i] / (k[i] + 1);
    sum = (sum + k[i] * i) % inf;
  }
  ans = sum;
  for (int i = n - 1; i >= 1; i--) {
    sum = ((sum - k[i] * i) % inf + inf) % inf;
    k[i] = 0;
    b[i] = a[i];
    int j = i - 1;
    while (j > 0 && get(a[j], b[j + 1]) < k[j]) {
      sum = ((sum - k[j] * j) % inf + inf) % inf;
      k[j] = get(a[j], b[j + 1]);
      sum = (sum + k[j] * j) % inf;
      b[j] = a[j] / (k[j] + 1);
      j--;
    }
    ans = (ans + sum) % inf;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
  return 0;
}
