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
  for (long long int &x : a) cin >> x;
  long long int sum = 0;
  long long int k = 0;
  for (long long int i = 0; i < n; i++) {
    sum += a[i];
  }
  if (sum % 2 == 0) {
    for (long long int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
  if (sum % 2 == 1) {
    if (isPrime(sum)) {
      sort(a.begin(), a.end());
      for (long long int i = 0; i < n; i++) {
        sum = sum - a[i];
        if (isPrime(sum)) {
          continue;
        } else {
          k = i + 1;
          break;
        }
      }
      for (long long int i = k; i < n; i++) {
        cout << i + 1 << " ";
      }
      cout << "\n";
    } else {
      for (long long int i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
      cout << "\n";
    }
  }
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
