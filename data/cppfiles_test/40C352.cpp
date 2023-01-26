#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265358979323844;
const long long int INF = 1e18;
const long long int N = 1e9 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void hue_hue_hue() {
  long long int m;
  cin >> m;
  long long int arr[2][m];
  for (long long int j = (long long int)(0); j < (long long int)(2); j++)
    for (long long int i = (long long int)(0); i < (long long int)(m); i++)
      cin >> arr[j][i];
  long long int preSumU[m], preSumD[m];
  preSumU[0] = arr[0][0];
  preSumD[0] = arr[1][0];
  for (long long int i = (long long int)(1); i < (long long int)(m); i++)
    preSumU[i] = preSumU[i - 1] + arr[0][i];
  for (long long int i = (long long int)(1); i < (long long int)(m); i++)
    preSumD[i] = preSumD[i - 1] + arr[1][i];
  long long int res = preSumU[m - 1] - preSumU[0];
  for (long long int i = (long long int)(0); i < (long long int)(m); i++)
    res = min(res, max((preSumU[m - 1] - preSumU[i]), (preSumD[i - 1])));
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int testCase = 1;
  cin >> testCase;
  while (testCase-- > 0) hue_hue_hue();
  return 0;
}
