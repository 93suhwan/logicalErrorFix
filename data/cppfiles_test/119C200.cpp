#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}
long long power(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  long long ans = power(a, b / 2, mod);
  ans *= ans;
  ans %= mod;
  if (b % 2) {
    ans *= a;
  }
  return ans % mod;
}
int sol() {
  long long n, sum = 0;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  if (sum % n == 0)
    cout << 0 << "\n";
  else
    cout << 1 << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test_case = 1;
  cin >> test_case;
  while (test_case--) {
    sol();
  }
  return 0;
}
