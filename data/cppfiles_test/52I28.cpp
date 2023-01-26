#include <bits/stdc++.h>
using namespace std;
vector<long long int> kthsetbit(long long int n) {
  long long int index = 0;
  vector<long long int> v;
  while (n != 0) {
    if ((n & 1) == 1) {
      v.push_back(index);
    }
    n = n >> 1;
    index = index + 1;
  }
  return v;
}
long long int binpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int sum = 0;
    vector<long long int> v = kthsetbit(k);
    for (long long int i = v.size() - 1; i >= 0; i--) {
      sum = (sum + binpow(n, v[i])) % 1000000007;
    }
    cout << sum % 1000000007 << endl;
  }
}
