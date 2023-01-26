#include <bits/stdc++.h>
using namespace std;
long long int bpow(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % 1000000007;
    b /= 2;
    a = (a * a) % 1000000007;
  }
  return ans;
}
int main() {
  long long int testc;
  cin >> testc;
  while (testc--) {
    long long int a, b;
    cin >> a >> b;
    if (b > a) swap(a, b);
    long long int n = a + b;
    long long int x = n / 2, y = (n + 1) / 2;
    long long int p1 = x;
    set<long long int> s;
    s.insert(a - x);
    s.insert(a - y);
    long long int z = n - a;
    for (int i = 1; i <= z; i++) {
      s.insert(a - x + 2 * i);
      s.insert(a - y + 2 * i);
    }
    cout << s.size() << "\n";
    for (auto i : s) cout << i << " ";
    cout << "\n";
  }
}
