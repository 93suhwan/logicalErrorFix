#include <bits/stdc++.h>
using namespace std;
vector<long long int> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long int> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
vector<long long int> primes;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int ans = 0;
  for (long long int i = 0; i < n; i++) {
    if (a[i] == i + 1) {
      continue;
    }
    if ((a[i] % (a[i] - (i + 1)) == i + 1)) {
      ans++;
    } else {
      cout << -1 << '\n';
      return;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t t1 = clock();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "Time elapsed: " << (double)(clock() - t1) / 1000 << " s" << '\n';
}
