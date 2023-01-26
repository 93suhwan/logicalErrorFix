#include <bits/stdc++.h>
using namespace std;
int size = 300001;
vector<long long int> dp(size, 0);
void init() {
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i < size; i++) {
    dp[i] = dp[i - 1] ^ i;
  }
}
int main() {
  long long int cases;
  cin >> cases;
  while (cases--) {
    long long int a, b;
    cin >> a >> b;
    long long int xOr = dp[a - 1];
    if (xOr == b)
      cout << a << endl;
    else if ((xOr ^ a) == b)
      cout << a + 2 << endl;
    else
      cout << a + 1 << endl;
  }
  return 0;
}
