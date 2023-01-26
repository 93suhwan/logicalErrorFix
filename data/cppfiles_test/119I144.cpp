#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100];
  int i, n;
  cin >> n;
  int sum = 0;
  for (i = 1; i <= n; i++) cin >> a[i];
  sum += a[i];
  if (sum % n == 0)
    cout << "0";
  else
    cout << "1";
  return 0;
}
