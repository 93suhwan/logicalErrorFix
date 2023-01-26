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
        long long int j = i + 1;
        long long int cnt = 0;
        bool g = 0;
        while (j < n) {
          if (cnt < 1) {
            if (a[j] == '0' && b[j] == '0') {
              cnt++;
            } else {
              if (a[i] - '0' + b[i] - '0' == 1) {
                sum += 3;
              } else {
                sum += 2;
              }
              g = 1;
              break;
            }
          } else {
            break;
          }
          j++;
        }
        if (g == 0) {
          sum++;
        } else {
          i = j;
        }
      } else {
        long long int j = i + 1;
        while (j < n) {
          if (a[j] == '0' || b[j] == '0') {
            sum += 2;
            break;
          }
          j++;
        }
        i = j;
      }
    }
    cout << sum << "\n";
  }
}
