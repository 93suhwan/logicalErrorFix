#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
void solveA() {
  int n;
  cin >> n;
  vector<int> a(31);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < 31; j++) {
      if (x >> j & 1) a[j]++;
    }
  }
  int temp = 0;
  for (int i = 0; i < 31; i++) temp = gcd(temp, a[i]);
  for (int i = 1; i <= n; i++)
    if (temp % i == 0) cout << i << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solveA();
  return 0;
}
