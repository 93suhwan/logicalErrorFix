#include <bits/stdc++.h>
using namespace std;
void swap(long long int x, long long int y) { x = x + (y - (y = x)); }
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int Gcd(vector<long long int> arr, long long int n) {
  long long int result = arr[0];
  for (long long int i = 1; i < n; i++) {
    result = gcd(arr[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    vector<long long int> odd;
    vector<long long int> even;
    for (long long int i = 0; i < n; i++) {
      if (i & 1) {
        odd.push_back(arr[i]);
      } else
        even.push_back(arr[i]);
    }
    long long int h1 = Gcd(even, even.size());
    long long int h2 = Gcd(odd, odd.size());
    bool possible1 = true, possible2 = true;
    for (long long int i = 1; i < n; i = i + 2) {
      if (arr[i] % h1 == 0) {
        possible1 = false;
      }
    }
    for (long long int i = 0; i < n; i = i + 2) {
      if (arr[i] % h2 == 0) {
        possible2 = false;
      }
    }
    if (possible1 == false && possible2 == false) {
      cout << "0"
           << "\n";
    } else if (possible2 == false) {
      cout << h1 << "\n";
    } else
      cout << h2 << "\n";
  }
  return 0;
}
