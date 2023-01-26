#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long int INF = 1e18 + 2;
bool compareBysecond(pair<long long int, long long int> a,
                     pair<long long int, long long int> b) {
  return a.first > b.first;
}
long long int gcd(long long int a, long long int b) {
  if (!a) return b;
  return gcd(b % a, a);
}
int log(long long int x) {
  int cnt = 0;
  while (x > 0) {
    cnt++;
    x = x >> 1;
  }
  return cnt;
}
long long int max(long long int a, long long int b) {
  if (a < b)
    return b;
  else
    return a;
}
long long int min(long long int a, long long int b) {
  if (a > b)
    return b;
  else
    return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << ' ' << n / 3 << '\n';
    } else if (n % 3 == 1) {
      cout << n / 3 + 1 << ' ' << n / 3 << '\n';
    } else
      cout << n / 3 << ' ' << n / 3 + 1 << '\n';
  }
  return 0;
}
