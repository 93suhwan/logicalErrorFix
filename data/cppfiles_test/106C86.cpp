#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << 2 << " ";
    for (int i = 1; i < n; i++) {
      cout << i + 2 << " ";
    }
    cout << '\n';
  }
  return 0;
}
