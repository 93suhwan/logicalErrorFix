#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T > 0) {
    long long n;
    cin >> n;
    long double arr[2005], sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      sum = sum + arr[i];
    }
    long double mean;
    mean = sum / n;
    if (ceil(mean) != mean) {
      cout << 0 << '\n';
    } else {
      sort(arr, arr + n);
      long long k = 0;
      while (arr[k] <= mean) {
        k++;
        if (k == n) {
          break;
        }
      }
      if (k == n) {
        cout << ((n) * (n - 1)) / 2 << '\n';
      } else {
        long long count = 0;
        long double sum2 = 0;
        for (long long i = 0; i < k; i++) {
          for (long long j = n - 1; j > i; j--) {
            sum2 = arr[i] + arr[j];
            sum2 = sum2 / 2;
            if (sum2 > mean) {
              continue;
            } else if (sum2 < mean) {
              break;
            } else if (sum2 == mean) {
              count++;
            }
          }
        }
        cout << count << '\n';
      }
    }
    T--;
  }
}
