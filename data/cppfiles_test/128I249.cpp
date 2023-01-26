#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
long long smallestDivisor(long long n) {
  if (n % 2 == 0) return 2;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return i;
  }
  return n;
}
void solve() {
  long long n;
  cin >> n;
  cout << n - 2 << " " << 1 << " " << 1 << endl;
  return;
  if (isPrime(n)) {
    for (int i = 2; i <= (n - 1) / 2; i++) {
      if (isPrime(i) && isPrime(n - 1 - i)) {
        cout << i << " " << n - i - 1 << " " << 1 << endl;
        break;
      }
    }
    return;
  } else {
    long long sd = smallestDivisor(n);
    vector<long long> allMultiples;
    for (int i = 1; i <= (n / sd); i++) {
      allMultiples.push_back(sd * i);
    }
    long long sum = n - sd;
    map<long long, long long> mp;
    for (int i = 0; i < allMultiples.size(); i++) {
      if (mp.find(sum - allMultiples[i]) != mp.end()) {
        cout << allMultiples[i] << " " << sum - allMultiples[i] << " " << sd
             << endl;
        return;
      }
      mp[allMultiples[i]]++;
    }
  }
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
