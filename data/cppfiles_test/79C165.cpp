#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  long long int temp[101] = {0};
  temp[1] = 1;
  for (long long int i = 2; i * i <= 100; i++) {
    if (!temp[i]) {
      for (long long int j = 2; i * j <= 100; j++) {
        temp[i * j] = 1;
      }
    }
  }
  vector<string> check;
  for (long long int i = 1; i <= 100; i++) {
    if (temp[i]) {
      string c = to_string(i);
      check.push_back(c);
    }
  }
  long long int m = check.size();
  while (t--) {
    long long int n;
    cin >> n;
    string a;
    cin >> a;
    long long int e = 0;
    for (long long int iter = 0; iter < m && e == 0; iter++) {
      string curr = check[iter];
      long long int j = 0, i;
      for (i = 0; i < curr.length() && j < n; i++) {
        while (j < n && a[j] != curr[i]) {
          j++;
        }
        if (j == n) {
          break;
        }
        j++;
      }
      if (i == curr.length()) {
        cout << curr.length() << endl << curr << endl;
        e = 1;
        break;
      }
    }
  }
  return 0;
}
