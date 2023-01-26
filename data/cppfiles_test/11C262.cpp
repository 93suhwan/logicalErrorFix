#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p);
const long long inf = 999999999;
const long long mod = 1e9 + 7;
bool tc = true;
void solve() {
  long long n, ans = 0;
  cin >> n;
  vector<vector<long long>> freq(5, vector<long long>(n, 0));
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    for (char ch : s) freq[ch - 'a'][i]++;
    for (long long j = 0; j < 5; j++) freq[j][i] = 2 * freq[j][i] - s.length();
  }
  for (long long i = 0; i < 5; i++) {
    sort(freq[i].begin(), freq[i].end(), greater<long long>());
    long long sum = 0;
    for (long long j = 0; j < n; j++) {
      sum += freq[i][j];
      if (sum <= 0)
        break;
      else
        ans = max(ans, j + 1);
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  clock_t start = clock();
  long long t = 1;
  if (tc) cin >> t;
  while (t--) solve();
  cerr << fixed << setprecision(6);
  cerr << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
  return 0;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
