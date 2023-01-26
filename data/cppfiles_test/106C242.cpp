#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1)
      cout << 1;
    else {
      for (long long int i = 2; i <= n + 1; i++) cout << i << " ";
    }
    cout << "\n";
  }
}
