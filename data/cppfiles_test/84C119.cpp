#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int numberOfElement, totalSum, ans;
    cin >> numberOfElement >> totalSum;
    ans = totalSum / ((numberOfElement / 2) + 1);
    cout << ans << endl;
  }
}
