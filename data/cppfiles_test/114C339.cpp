#include <bits/stdc++.h>
const int N = 2001;
int m = 1000000007;
int a[N][N], s[N];
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, count = 0;
    cin >> n;
    long long int a[n + 1];
    vector<long long int> v;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    count = n / 2;
    for (i = v.size() - 1; i >= 0; i--) {
      cout << v[i] << " " << v[0] << '\n';
      count--;
      if (count == 0) break;
    }
  }
  return 0;
}
