#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, j, count = 0;
    cin >> n;
    long long int arr[n + 1];
    long long int mx = 0;
    bool a = 0, b = 0;
    set<long long int> s;
    set<long long int> s1;
    for (i = 1; i <= n; i++) {
      cin >> arr[i];
      mx = max(arr[i], mx);
      s1.insert(arr[i]);
      if (arr[i] % 3 == 1) {
        s.insert(arr[i]);
        a = 1;
      } else if (arr[i] % 3 == 2)
        b = 1;
    }
    if (mx % 3 == 0) {
      if (a == 1 || b == 1)
        cout << mx / 3 + 1 << '\n';
      else
        cout << mx / 3 << '\n';
    } else {
      if (mx < 3)
        cout << a + b << '\n';
      else if (mx % 3 == 1) {
        if ((s1.find(mx - 1) != s1.end() && b == 1) ||
            (b == 1 && s1.find(1) != s1.end()))
          cout << mx / 3 + 2 << '\n';
        else
          cout << mx / 3 + 1 << '\n';
      } else if (a == 1 && b == 1)
        cout << mx / 3 + 2 << '\n';
      else
        cout << mx / 3 + 1 << '\n';
    }
  }
  return 0;
}
