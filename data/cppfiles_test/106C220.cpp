#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long getSum(long long m) {
  long long sum = 0;
  while (m != 0) {
    sum = sum + m % 10;
    m = m / 10;
  }
  return sum;
}
void debug_a(long long arr[], long long n) {
  for (long long i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
void debug_v(vector<long long> v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void lldebug(long long n) { cout << n << endl; }
void sdebug(string s) { cout << s << endl; }
void lddebug(long double n) { cout << n << endl; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
static long long start = 1;
void sumedh() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a = 2;
  for (long long i = 0; i < n; i++) {
    cout << a << " ";
    a++;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    sumedh();
  }
}
