#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int sqr(long long int n) { return n * n; }
long long int mod = 1e9 + 7;
long long int pow(long long int p, long long int d) {
  return d ? (pow((p * p) % mod, d >> 1) * (d & 1 ? p : 1)) % mod : 1ll;
}
vector<bool> SieveOfEratosthenes(long long int num) {
  vector<bool> soe;
  soe.assign(num + 1, true);
  soe[0] = false;
  soe[1] = false;
  for (long long int i = 2; i * i <= num; i++) {
    if (soe[i] == true) {
      for (long long int j = i * 2; j <= num; j += i) soe[j] = false;
    }
  }
  return soe;
}
long long int bs(vector<long long int> &v, long long int l, long long int r,
                 long long int key) {
  while (l + 1 < r) {
    long long int mid = (l + r) / 2;
    if (v[mid] > key)
      r = mid;
    else
      l = mid;
  }
  return l;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    ;
    string k = s;
    sort(k.begin(), k.end());
    long long int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != k[i]) cnt++;
    }
    cout << cnt << '\n';
  }
}
