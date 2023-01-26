#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, sum = 0;
    cin >> n;
    for (long long int i = 1; i * i <= n; i++)
      if (i * i <= n) sum++;
    for (long long int i = 1; i * i * i <= n; i++)
      if (i * i * i <= n) sum++;
    for (long long int i = 1; i * i * i * i * i * i <= n; i++)
      if (i * i * i * i * i * i <= n) sum--;
    cout << sum << endl;
  }
}
