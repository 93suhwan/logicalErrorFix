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
  long long int a = 0, b = 0, c = 0, d = 0;
  for (long long int i = (long long int)(0); i < (long long int)(m); i++) {
    cin >> arr[0][i];
    if (i != 0) a += arr[0][i];
    if (i > m / 2) c += arr[0][i];
  }
  for (long long int i = (long long int)(0); i < (long long int)(m); i++) {
    cin >> arr[1][i];
    if (i != m - 1) b += arr[1][i];
    if (i < m / 2) d += arr[1][i];
  }
  long long int res = min({a, b, c});
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(9);
  long long int testCase = 1;
  cin >> testCase;
  while (testCase-- > 0) hue_hue_hue();
  return 0;
}
