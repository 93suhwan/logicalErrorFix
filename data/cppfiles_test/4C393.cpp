#include <bits/stdc++.h>
using namespace std;
const long long SZ = 1e5 + 7;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const long long MAX = 1e5 + 5;
priority_queue<long long int, vector<long long int>, greater<long long int> >
    minheap;
priority_queue<long long int> maxheap;
long long int powermod(long long int a, long long int n) {
  long long int ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a);
    n = n >> 1;
    a = (a * a);
  }
  return ans;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
void testcase() {
  long long int x;
  cin >> x;
  long long int n = x;
  n--;
  long long int cnt = 0;
  for (long long int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      cout << i << " ";
      cnt++;
    }
    if (cnt >= 2) break;
  }
  if (cnt < 2) cout << n;
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    testcase();
  }
}
