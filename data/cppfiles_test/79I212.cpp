#include <bits/stdc++.h>
using namespace std;
long long int _ceil(long long int x, long long int y) {
  long long int r = (x / y) + ((x % y) != 0);
  return r;
}
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long int const N = 121;
long long int is_prime[N];
void sieve() {
  is_prime[0] = 1;
  is_prime[1] = 0;
  for (long long int i = 0; i < N; i++) {
    is_prime[i] = 1;
  }
  long long int i = 2;
  while (i * i <= N) {
    if (is_prime[i] == 0) {
      i++;
      continue;
    }
    long long int j = 2 * i;
    while (j < N) {
      is_prime[j] = 0;
      j += i;
    }
    i++;
  }
}
int32_t main() {
  c_p_c();
  long long int t;
  cin >> t;
  while (t--) {
    sieve();
    long long int k;
    cin >> k;
    string s;
    cin >> s;
    long long int ans, ans1;
    long long int a[k];
    long long int d = k - 1;
    for (long long int i = 0; i < k; i++) {
      a[i] = s[i] - 48;
    }
    for (long long int i = 0; i < k; i++) {
      bool f = false;
      if (is_prime[a[i]] == 0) {
        ans = 1;
        ans1 = a[i];
        break;
      }
      for (long long int j = i + 1; j < k; j++) {
        long long int l1 = (a[i] * 10) + a[j];
        if (is_prime[l1] == 0) {
          ans = 2;
          ans1 = l1;
          f = true;
          break;
        }
      }
      if (f == true) break;
    }
    cout << ans << endl;
    cout << ans1 << endl;
  }
  return 0;
}
