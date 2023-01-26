#include <bits/stdc++.h>
using namespace std;
long long po(long long a, long long b) {
  long long m = 1;
  while (b--) {
    m = m % 1000000007;
    m *= a;
    m = m % 1000000007;
  }
  return m;
}
bool pri(int a) {
  if (a == 1) return 0;
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return 0;
    }
  }
  return 1;
}
vector<long long> v;
string s[100];
string a;
int main() {
  long long t, n, o;
  cin >> t;
  while (t--) {
    cin >> n >> n;
    o = 0;
    o += n % 10;
    n /= 10;
    while (n) {
      o += n % 10;
      if (n % 10) o++;
      n /= 10;
    }
    cout << o << endl;
  }
  return 0;
}
