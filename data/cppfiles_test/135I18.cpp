#include <bits/stdc++.h>
using namespace std;
long long power(long long, long long);
bool isPrime(long long);
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long score1 = 0, score2 = 0;
    long long temp_k = k;
    for (long long i = n - 1; i >= 0;) {
      if (temp_k > 0) {
        score1 += (arr[i - 1] / arr[i]);
        temp_k--;
        i -= 2;
      } else {
        score1 += arr[i];
        i--;
      }
    }
    long long l = 0, h = n - 1;
    temp_k = k;
    while (l <= h && temp_k > 0) {
      if (l != h) {
        score2 += (arr[l] / arr[h]);
      } else {
        score2 += arr[l];
      }
      temp_k--;
      l++;
      h--;
    }
    for (long long i = l; i <= h; i++) {
      score2 += arr[i];
    }
    cout << min(score1, score2) << "\n";
  }
  return 0;
}
