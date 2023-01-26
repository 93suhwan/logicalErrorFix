#include <bits/stdc++.h>
using namespace std;
int check_prime(long long int num) {
  int flag = 1;
  if (num % 2 == 0 && num != 2)
    flag = 0;
  else {
    for (long long int i = 3; i <= sqrt(num); i += 2) {
      if (num % i == 0) {
        flag = 0;
        break;
      }
    }
  }
  return flag;
}
int main() {
  long long int t = 1;
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int sum = 0;
    vector<long long int> a(n);
    map<long long int, long long int> mp;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      mp[a[i]] = i + 1;
    }
    if (!check_prime(sum)) {
      cout << n << "\n";
      for (long long int i = 0; i < n; i++) cout << mp[a[i]] << " ";
      cout << "\n";
      continue;
    }
    for (long long int i = 0; i < n; i++) {
      if (a[i] & 1) {
        remove(a.begin(), a.end(), a[i]);
        break;
      }
    }
    cout << n - 1 << "\n";
    for (long long int i = 0; i < n - 1; i++) cout << mp[a[i]] << " ";
    cout << "\n";
  }
}
