#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i;
    cin >> n;
    pair<long long int, long long int> p[n];
    for (i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      p[i].first = x;
      p[i].second = i;
    }
    sort(p, p + n);
    long long int a = 0, c = p[n - 1].second;
    for (i = n - 2; i >= 0; i--) {
      if (p[i].second > c) {
        a++;
        c = p[i].second;
      }
    }
    cout << a << endl;
  }
  return 0;
}
