#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
long long factinverse[N + 1], inverse[N + 1], fact[N + 1];
long long binomial(long long N, long long R) {
  return (R > N) ? 0
                 : fact[N] * factinverse[R] % 998244353 * factinverse[N - R] %
                       998244353;
}
void precompute() {
  inverse[0] = inverse[1] = 1;
  for (int i = 2; i <= N; i++)
    inverse[i] =
        inverse[998244353 % i] * (998244353 - 998244353 / i) % 998244353;
  factinverse[0] = factinverse[1] = 1;
  for (int i = 2; i <= N; i++)
    factinverse[i] = inverse[i] * factinverse[i - 1] % 998244353;
  fact[0] = 1;
  for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % 998244353;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  precompute();
  long long n, k;
  string str;
  cin >> n >> k >> str;
  if (k == 0) {
    cout << "1\n";
    return 0;
  }
  int left = 0;
  int right = -1;
  int onecount = 0;
  while (onecount != k && right + 1 < n) {
    if (str[right + 1] == '1') {
      onecount++;
    }
    right++;
  }
  if (onecount != k) {
    cout << "1\n";
    return 0;
  }
  while (right + 1 < n && str[right + 1] == '0') {
    right++;
  }
  long long ans = 0;
  ans = binomial(right - left + 1, k);
  while (left < n && right < n) {
    while (left < n && onecount == k) {
      if (str[left] == '1') {
        onecount--;
      }
      left++;
    }
    if (left == n) break;
    while (onecount != k && right + 1 < n) {
      if (str[right + 1] == '1') {
        onecount++;
      }
      right++;
    }
    if (onecount != k) break;
    while (right + 1 < n && str[right + 1] == '0') {
      right++;
    }
    int flag = 0;
    for (int i = right; i >= left + k - 2; i--) {
      if (str[i] == '1' && !flag) {
        flag = 1;
        continue;
      }
      ans += binomial(i - left, k - 1);
      ans %= 998244353;
    }
  }
  cout << ans << "\n";
}
