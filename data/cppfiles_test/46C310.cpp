#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, count = 0;
  cin >> t;
  for (int i = 0; i < 100000; i++)
    ;
  for (int i = 0; i < 100000; i++)
    ;
  for (int i = 0; i < 100000; i++)
    ;
  for (int i = 0; i < 100000; i++)
    ;
  for (int i = 0; i < 100000; i++)
    ;
  while (t--) {
    cin >> n;
    long long int flag = 0;
    count = 0;
    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long int a1 = a[0];
    for (int i = 1; i < n; i++) {
      a1 = max(a1, a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == a1) {
        break;
      } else if (a[i] > flag) {
        count++;
        flag = a[i];
      }
    }
    cout << count << endl;
  }
  return 0;
}
