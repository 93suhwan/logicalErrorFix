#include <bits/stdc++.h>
using namespace std;
long long power(long long, long long);
bool isPrime(long long);
bool comp(long long n1, long long n2) { return n1 > n2; }
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
    sort(arr.begin(), arr.end(), comp);
    long long score = 0;
    for (long long i = 0; i < k; i++) {
      score += (arr[i + k] / arr[i]);
    }
    for (long long i = 2 * k; i < n; i++) {
      score += arr[i];
    }
    cout << score << "\n";
  }
  return 0;
}
