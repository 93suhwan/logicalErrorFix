#include <bits/stdc++.h>
using namespace std;
const long long int MAX = INT_MAX;
const long long int MIN = INT_MIN;
long long int dx[4] = {-1, 1, 0, 0};
long long int dy[4] = {0, 0, 1, -1};
long long int inverse(long long int i) {
  if (i == 1) return 1;
  return (1000000007 -
          ((1000000007 / i) * inverse(1000000007 % i)) % 1000000007 +
          1000000007) %
         1000000007;
}
long long int power(long long int x, long long int y, long long int m) {
  long long int ans = 1;
  x = x % m;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % m;
    y = y >> 1;
    x = (x * x) % m;
  }
  return ans;
}
long long int parent[100001];
long long int find(long long int a) {
  if (parent[a] < 0) return a;
  long long int x = find(parent[a]);
  parent[a] = x;
  return x;
}
void Union(long long int a, long long int b) {
  parent[b] += parent[a];
  parent[a] = b;
}
void code() {
  long long int n;
  cin >> n;
  string second;
  cin >> second;
  long long int flag = 0;
  long long int flap;
  for (long long int i = 0; i < n; i++) {
    if (second[i] == '0') {
      flap = i;
      flag = 1;
      break;
    }
  }
  if (flag) {
    if (flap <= (n / 2)) {
      long long int x = flap + 2;
      long long int y = n;
      long long int a = flap + 1;
      long long int b = n;
      cout << x << " " << y << " " << a << " " << b << "\n";
    } else {
      long long int x = 1;
      long long int y = flap;
      long long int a = 1;
      long long int b = flap + 1;
      cout << x << " " << y << " " << a << " " << b << "\n";
    }
  } else {
    cout << 1 << " " << n / 2 << " " << n / 2 + 1 << " " << n << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  t = 1;
  cin >> t;
  while (t--) {
    code();
  }
  return 0;
}
