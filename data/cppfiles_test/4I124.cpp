#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int num;
  cin >> num;
  long long int range = sqrt(num);
  int i;
  for (i = 2; i <= range; i++) {
    if (i + 2 > range) {
      if (num % i == num % (i + 2)) {
        break;
      }
    }
  }
  cout << i << " " << i + 2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int testCases;
  cin >> testCases;
  while (testCases--) {
    solve();
  }
  return 0;
}
