#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
bool cmp(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  if (a.first != b.first)
    return a.first > b.first;
  else
    return a.second > b.second;
}
long long int binarySearch(vector<long long int> v, long long int l,
                           long long int r, long long int x) {
  while (l <= r) {
    long long int mid = l + (r - l) / 2;
    if (v[mid] == x)
      return mid;
    else if (v[mid] < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
long long int power(long long int x, long long int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return power(x * x, n / 2);
  else
    return x * power(x * x, (n - 1) / 2);
}
long long int ModularExpo(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) cout << i + 2 << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
