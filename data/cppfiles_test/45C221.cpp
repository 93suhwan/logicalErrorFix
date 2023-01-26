#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 300000;
const long long int INF = 2e18;
long long int factorialNumInverse[MAX + 1];
long long int naturalNumInverse[MAX + 1];
long long int fact[MAX + 1];
void InverseofNumber() {
  naturalNumInverse[0] = naturalNumInverse[1] = 1LL;
  for (long long int i = 2; i < MAX; i++)
    naturalNumInverse[i] = naturalNumInverse[998244353 % i] *
                           (998244353 - 998244353 / i) % 998244353;
}
void InverseofFactorial() {
  factorialNumInverse[0] = factorialNumInverse[1] = 1LL;
  for (long long int i = 2; i < MAX; i++)
    factorialNumInverse[i] =
        (naturalNumInverse[i] * factorialNumInverse[i - 1]) % 998244353;
}
void factorial() {
  fact[0] = 1LL;
  for (long long int i = 1; i < MAX; i++) {
    fact[i] = (fact[i - 1] * i) % 998244353;
  }
}
long long int Binomial(long long int N, long long int R) {
  long long int ans = ((fact[N] * factorialNumInverse[R]) % 998244353 *
                       factorialNumInverse[N - R]) %
                      998244353;
  return ans;
}
void solve(int t) {
  int n;
  cin >> n;
  vector<int> odds;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x & 1) {
      odds.push_back(i);
    }
  }
  int mid = (n + 1) / 2;
  if (odds.size() > mid || (n - mid) > odds.size()) {
    cout << -1 << endl;
    return;
  }
  sort(odds.begin(), odds.end());
  if (n & 1) {
    int ans = 0, j;
    if (odds.size() == n / 2) {
      j = 0;
      for (int i = 1; i < n; i += 2) {
        ans += abs(odds[j++] - i);
      }
    } else {
      j = 0;
      for (int i = 0; i < n; i += 2) {
        ans += abs(odds[j++] - i);
      }
    }
    cout << ans << endl;
  } else {
    int ans = 0, j = 0;
    for (int i = 1; i < n; i += 2) {
      ans += abs(odds[j++] - i);
    }
    int ans2 = 0;
    j = 0;
    for (int i = 0; i < n; i += 2) {
      ans2 += abs(odds[j++] - i);
    }
    cout << min(ans, ans2) << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  cin >> t;
  factorial();
  InverseofNumber();
  InverseofFactorial();
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
