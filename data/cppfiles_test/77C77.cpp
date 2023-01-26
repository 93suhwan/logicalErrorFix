#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
long long int pref[50 * 100001] = {};
long long int N;
long long int MOD;
long long int sum(long long int l, long long int r) {
  r = min(N, r);
  return (pref[l] - pref[r + 1] + MOD) % MOD;
}
void solve() {
  long long int n;
  cin >> n;
  N = n;
  cin >> MOD;
  pref[n] = 1;
  for (long long int i = n - 1; i >= 1; i--) {
    long long int curr = sum(i + 1, n);
    long long int cnt = 2;
    while (true) {
      if (cnt * i > n) break;
      curr += sum(cnt * i, cnt * i + cnt - 1);
      curr %= MOD;
      cnt++;
    }
    pref[i] = (pref[i + 1] + curr) % MOD;
  }
  cout << sum(1, 1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
}
