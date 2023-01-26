#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
int adigit(long long int n) {
  n = n % 10;
  return n;
}
int getSum(string str) {
  int sum = 0;
  for (int i = 0; i < str.length(); i++) {
    sum = sum + str[i] - 48;
  }
  return sum;
}
bool isPrime(unsigned long long int n) {
  if (n <= 1) return false;
  for (unsigned long long int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  long long int sum = 0;
  for (long long int &x : a) cin >> x;
  for (long long int i = 0; i < n; i++) {
    sum += a[i];
  }
  if (sum % 2 == 0 || !isPrime(sum)) {
    cout << n << endl;
    for (long long int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << endl;
    return;
  }
  long long int cnt = -1;
  for (int i = 0; i < n; i++) {
    if ((sum - a[i]) % 2 == 0) {
      cnt = a[i];
      break;
    }
  }
  long long int flag = 1;
  cout << n - 1 << endl;
  for (int i = 0; i < n; i++) {
    if (flag && a[i] == cnt) {
      flag = 0;
    } else {
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
