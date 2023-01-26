#include <bits/stdc++.h>
long long int prime = 1000000007;
long long int INF = 1000000000000000000;
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int a[n], j;
    for (j = 0; j < n; j++) cin >> a[j];
    long long int z = 0, o = 0;
    for (j = 0; j < n; j++) {
      if (a[j] == 1)
        o++;
      else if (a[j] == 0)
        z++;
    }
    cout << o * (pow(2, z)) << "\n";
  }
  return (0);
}
