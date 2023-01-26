#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, s;
    cin >> n >> s;
    long long int ans;
    if (n % 2) {
      ans = (n + 1) / 2;
    } else {
      ans = n / 2;
    }
    ans--;
    long long int k = n - ans;
    cout << s / k << endl;
  }
  return 0;
}
