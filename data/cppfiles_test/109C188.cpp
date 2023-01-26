#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, c = 0, sum = 0;
    string s;
    cin >> n;
    long long a[n];
    cin >> s;
    for (i = 0; i < n; i++) {
      a[i] = (int)(s[i] - '0');
    }
    for (i = 0; i <= n - 2; i++) {
      if (a[i] > 0) c++;
      sum += a[i];
    }
    sum += c;
    sum += a[n - 1];
    cout << sum;
    cout << endl;
  }
}
