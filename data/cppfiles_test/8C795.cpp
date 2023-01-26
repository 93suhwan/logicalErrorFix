#include <bits/stdc++.h>
using namespace std;
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
vector<long long> allfactors(long long n) {
  vector<long long> v;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      v.push_back(i);
      if ((n / i) != i) v.push_back(n / i);
    }
  }
  v.push_back(1);
  v.push_back(n);
  return v;
}
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  long long n;
  cin >> n;
  long long c1, c2;
  c2 = (n) / 3;
  c1 = n / 3;
  if (c1 < c2)
    c1 += n % 3;
  else {
    c2 += (n % 3) / 2;
    if ((n % 3) == 1) c1++;
  }
  cout << c1 << " " << c2 << endl;
}
int main() {
  fastio();
  long long _t;
  cin >> _t;
  while (_t--) {
    solve();
  }
  return 0;
}
