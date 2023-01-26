#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323846;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long dig_count(long long n) {
  long long c = 0;
  while (n) {
    c++;
    n /= 10;
  }
  return c;
}
long long powt(int n) {
  n--;
  long long ans = 1;
  while (n > 0) {
    ans *= 10;
    n--;
  }
  return ans;
}
vector<string> a;
long long fun(long long n, long long i) {
  string k = a[i];
  long long kc = k.length();
  long long ki = 0;
  long long nc = powt(dig_count(n));
  long long ans = 0;
  while (nc != 0 && ki != kc) {
    if ((k[ki] - '0') == n / nc) {
      ki++;
      n %= nc;
    } else {
      ans++;
      n %= nc;
    }
    nc /= 10;
  }
  while (ki != kc) {
    ki++;
    ans++;
  }
  while (nc) {
    nc /= 10;
    ans++;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t = 1, kc;
  cin >> t;
  for (int i = 0; i <= 30; i++) {
    a.push_back(to_string(1 << i));
  }
  a.push_back("2147483648");
  a.push_back("4294967296");
  a.push_back("8589934592");
  a.push_back("17179869184");
  a.push_back("34359738368");
  a.push_back("68719476736");
  a.push_back("137438953472");
  a.push_back("274877906944");
  a.push_back("549755813888");
  a.push_back("1099511627776");
  long long pq = a.size();
  for (kc = 1; kc <= t; kc++) {
    long long n, m, i, k, j, ans = 0;
    cin >> n;
    ans = dig_count(n) + 1;
    for (i = 0; i < pq; i++) {
      ans = min(fun(n, i), ans);
    }
    cout << ans << "\n";
  }
  return 0;
}
