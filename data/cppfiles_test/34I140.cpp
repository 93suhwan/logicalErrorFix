#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, INF = 1e18, mod = 1e9 + 7;
int n, k, arr[N];
void doWork() {
  cin >> n >> k;
  long long mx = -INF;
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
    if (i == 1) continue;
    mx = max(mx, i * (i - 1) - (k * (arr[i] | arr[i - 1])));
  }
  cout << mx << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) doWork();
}
