#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << n / 2 << " " << n - 1;
  }
  return 0;
}
