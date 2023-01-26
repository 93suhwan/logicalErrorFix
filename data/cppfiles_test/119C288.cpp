#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void template_test() {
  long long int n, i, j, k, m;
  for (i = 0; i < 1000000; i++)
    ;
  for (i = 0; i < 1000000; i++)
    ;
  for (i = 0; i < 1000000; i++)
    ;
  for (i = 0; i < 1000000; i++)
    ;
  for (i = 0; i < 1000000; i++)
    ;
  for (i = 0; i < 1000000; i++)
    ;
  for (i = 0; i < 1000000; i++)
    ;
  for (i = 0; i < 1000000; i++)
    ;
}
int power(int a, int b, int p) {
  if (a == 0) return 0;
  int res = 1;
  if (a >= p) a = a % p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
void SeiveOfEratosthenes(int n);
int main() {
  long long int t, i;
  cin >> t;
  while (t--) {
    template_test();
    for (i = 0; i < 1000000; i++)
      ;
    for (i = 0; i < 1000000; i++)
      ;
    for (i = 0; i < 1000000; i++)
      ;
    for (i = 0; i < 1000000; i++)
      ;
    for (i = 0; i < 1000000; i++)
      ;
    for (i = 0; i < 1000000; i++)
      ;
    for (i = 0; i < 1000000; i++)
      ;
    for (i = 0; i < 1000000; i++)
      ;
    for (i = 0; i < 1000000; i++)
      ;
    long long int n, i, j, k, m;
    cin >> n;
    long long int sum = 0;
    vector<long long int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
