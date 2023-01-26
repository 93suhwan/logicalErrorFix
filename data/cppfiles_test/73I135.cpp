#include <bits/stdc++.h>
using namespace std;
int getSum(long long m) {
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
int gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
static long long start = 1;
void sumedh() {
  long long sum = 0;
  long long sum1 = 0;
  long long sum2 = 0;
  long long cnt1 = 0;
  long long cnt2 = 0;
  long long res = 0;
  long long flag = 0;
  long long ans = 0;
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long count = 0;
  bool swapped = true;
  while (swapped) {
    swapped = false;
    if (count % 2 == 0) {
      for (long long i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
          if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            swapped = true;
          }
        }
      }
    } else {
      for (long long i = 0; i < n - 1; i++) {
        if (i % 2 != 0) {
          if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            swapped = true;
          }
        }
      }
    }
    if (swapped) {
      count++;
    }
  }
  cout << count << endl;
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
