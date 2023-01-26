#include <bits/stdc++.h>
using namespace std;
long long ans[4000005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long sum = 1, sum1 = 0;
  ans[1] = 1;
  for (int i = 2; i <= n; i++) {
    sum1 = (sum1 + ans[i] + 1) % m;
    ans[i] = (sum + sum1) % m;
    sum = (sum + ans[i]) % m;
    for (int j = 2 * i; j <= n; j += i)
      ans[j] = (ans[j] + ans[i] - ans[i - 1]) % m;
  }
  cout << (ans[n] + m) % m << endl;
  return 0;
}
