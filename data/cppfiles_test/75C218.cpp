#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
template <typename... T>
void debug(T &&...args) {
  ((cerr << args << " "), ...);
  cerr << "\n";
}
long long int gcd(long long int a, long long int b) {
  return a ? gcd(b % a, a) : b;
}
long long int minv(long long int a, long long int b) { return a < b ? a : b; }
long long int maxv(long long int a, long long int b) { return a > b ? a : b; }
void swapv(long long int &a, long long int &b) {
  a = a + b;
  b = a - b;
  a = a - b;
}
long long int power(long long int a, long long int b, long long int m = mod) {
  if (a == 0 || b == 1) return a;
  if (b == 0) return 1;
  long long int ans = 1;
  while (b >= 1) {
    if (b & 1) {
      b--;
      ans = (ans * a) % m;
    }
    a = (a * a) % m;
    b = b >> 1;
  }
  return ans;
}
long long int logv(long long int x) {
  long long int ans = -1;
  while (x) {
    x = x >> 1;
    ans++;
  }
  return ans;
}
long long int inv(long long int a, long long int m) {
  return power(a, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<pair<long long int, long long int>> vec;
    for (int i = 0; i < n; i++) {
      long long int size;
      cin >> size;
      long long int pwr;
      cin >> pwr;
      long long int req = pwr + 1;
      int count = 0;
      for (int j = 1; j < size; j++) {
        long long int pwr;
        cin >> pwr;
        count++;
        req = maxv(req, pwr + 1 - count);
      }
      vec.push_back({req, size});
    }
    sort(vec.begin(), vec.end());
    long long int ans = 0, count = 0;
    for (int i = 0; i < vec.size(); i++) {
      ans = maxv(ans, vec[i].first - count);
      count += vec[i].second;
    }
    cout << ans;
    cout << "\n";
    ;
  }
  return 0;
}
