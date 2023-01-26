#include <bits/stdc++.h>
using namespace std;
long long int getN(long long int sum) {
  sum = sum * 8;
  sum = sqrt(sum + 1) - 1;
  sum /= 2;
  return sum;
}
long long int apSum(long long int n) {
  long long int a = 1, d = 1;
  long long int res = (2 * a + (n - 1) * d) * n;
  res /= 2;
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isPrime(long long int n) {
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
void solveKaro() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  for (long long int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  };
  sort(arr.begin(), arr.end());
  long long int sum = arr[0], ans = arr[0];
  for (long long int i = 1; i < n; i++) {
    ans = max(arr[i] - sum, ans);
    sum += (arr[i] - sum);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tCase = 1;
  cin >> tCase;
  while (tCase--) {
    solveKaro();
  }
}
