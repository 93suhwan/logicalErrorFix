#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string a, b;
    long long int sum = 0;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
      if ((a[i] - '0') + (b[i] - '0') == 1) {
        sum += 2;
      } else if (a[i] == '0' && b[i] == '0') {
        if (i == n - 1) {
          sum += 1;
        } else {
          if (a[i + 1] - '0' + b[i + 1] - '0' == 2) {
            sum += 2;
            i++;
          } else if (a[i + 1] - '0' + b[i + 1] - '0' == 1) {
            sum += 1;
          } else {
            sum += 1;
          }
        }
      } else {
        if (i != n - 1) {
          if (a[i + 1] == '0' || b[i + 1] == '0') {
            sum += 2;
            i++;
          }
        }
      }
    }
    cout << sum << "\n";
  }
}
