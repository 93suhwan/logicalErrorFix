#include <bits/stdc++.h>
using namespace std;
int dir_x[] = {-1, 1, 0, 0};
int dir_y[] = {0, 0, -1, 1};
int TC;
long long gcd(long long a, long long b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  ;
  cin >> TC;
  for (__typeof(TC + 1) t = 1; t < TC + 1; t++) {
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for (__typeof(n) i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    if (sum % n)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}
