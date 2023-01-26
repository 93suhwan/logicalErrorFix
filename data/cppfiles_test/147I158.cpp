#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
int* prime;
bool sorter() { return true; }
long long intfromstring(string s) {
  int n = s.length();
  long long num = 0;
  for (long long i = 0; i < n; i += 1) num = num * 10 + (s[i] - '0');
  return num;
}
long long factn(long long n) {
  long long prod = 1;
  if (n == 0) return 1;
  for (long long i = 1; i < n + 1; i += 1) prod = ((prod % M) * (i % M)) % M;
  return prod % M;
}
long long factlogn(long long lo, long long hi) {
  if (hi - lo == 1) return hi * lo;
  if (hi - lo == 2) return hi * (hi - 1) * (lo);
  int mid = (hi + lo) / 2;
  return factlogn(lo, mid) * factlogn(mid + 1, hi);
}
long long binarySearch(long long arr[], long long lo, long long hi,
                       long long x) {
  if (hi - lo > 1) {
    long long mid = (lo + hi) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, lo, mid - 1, x);
    if (arr[mid] < x) return binarySearch(arr, mid + 1, hi, x);
  }
  return -1;
}
long long firstOccurence(long long arr[], long long lo, long long hi,
                         long long x) {
  if (hi - lo > 1) {
    long long mid = (lo + hi) / 2;
    if (arr[mid] == x) return firstOccurence(arr, lo, mid, x);
    if (arr[mid] < x) return firstOccurence(arr, mid + 1, hi, x);
    if (arr[mid] > x) return firstOccurence(arr, lo, mid - 1, x);
  }
  if (arr[lo] == x) return lo;
  if (arr[hi] == x) return hi;
  return -1;
}
long long lastOccurence(long long arr[], long long lo, long long hi,
                        long long x) {
  if (hi - lo > 1) {
    long long mid = (lo + hi) / 2;
    if (arr[mid] == x) return lastOccurence(arr, mid, hi, x);
    if (arr[mid] < x) return lastOccurence(arr, mid + 1, hi, x);
    if (arr[mid] > x) return lastOccurence(arr, lo, mid - 1, x);
  }
  if (arr[hi] == x) return hi;
  if (arr[lo] == x) return lo;
  return -1;
}
long long count(long long arr[], long long n, long long x) {
  return lastOccurence(arr, 0, n - 1, x) - firstOccurence(arr, 0, n - 1, x) + 1;
}
long long int maxl(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int minl(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int absl(long long int a) {
  if (a < 0) return -a;
  return a;
}
long long powb(long long base, long long po) {
  base %= M;
  if (base == 1 || po == 0) return 1;
  if (po == 1) return base % M;
  if (po & 1) {
    long long x = powb(base, po / 2) % M;
    return (((x * x) % M) * base) % M;
  }
  long long x = powb(base, po / 2) % M;
  return (x * x) % M;
}
long long powbwomom(long long base, long long po) {
  if (base == 1 || po == 0) return 1;
  if (po == 1) return base;
  if (po & 1) {
    long long x = powb(base, po / 2);
    return (((x * x)) * base);
  }
  long long x = powb(base, po / 2);
  return (x * x);
}
string Binary(long long n) {
  stack<char> bin;
  while (n) {
    if (n & 1)
      bin.push('1');
    else
      bin.push('0');
    n = n >> 1;
  }
  string str = "";
  while (bin.size()) {
    str.push_back(bin.top());
    bin.pop();
  }
  return str;
}
void sieve(int n) {
  prime = new int[n + 1];
  for (long long i = 0; i < n + 1; i += 1) prime[i] = 1;
  prime[0] = 0;
  prime[1] = 0;
  for (long long i = 2; i < sqrt(n) + 1; i += 1) {
    for (long long j = i * 2; j < n + 1; j += i) prime[j] = 0;
  }
}
void google(int a) {
  cout << "Case#" << a << ": ";
  return;
}
void testCase() {
  string s;
  cin >> s;
  if (s[0] == s[s.size() - 1]) {
    cout << "YES" << '\n';
    return;
  }
  cout << "NO" << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  int a = t;
  sieve(10001);
  while (t--) {
    testCase();
  }
  return 0;
}
