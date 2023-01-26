#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    unordered_map<long long, long long> make_pair;
    for (long long i = 0; i < n; i++) {
      long long no;
      cin >> no;
      arr[i] = no;
      if (make_pair[no] < k) {
        make_pair[no]++;
      }
    }
    for (long long i = 0; i < n; i++) {
      long long no = arr[i];
      cout << make_pair[no] << " ";
      if (make_pair[no] > 0) {
        make_pair[no]--;
      }
    }
    cout << endl;
  }
  return 0;
}
