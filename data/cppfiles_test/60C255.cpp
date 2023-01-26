#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
vector<long long int> getPrimeFactors(long long int n) {
  vector<long long int> to_return;
  while (n % 2 == 0) {
    to_return.push_back(2);
    n = n / 2;
  }
  for (long long int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      to_return.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) to_return.push_back(n);
  return to_return;
}
bool isStringPalindrome(string s) {
  long long int size = s.length();
  if (size == 1) return true;
  for (int i = 0; i <= (size - 1) / 2; i++) {
    if (s[i] != s[size - i - 1]) return false;
  }
  return true;
}
long long int factorial(long long int n) {
  if (n == 0) return 1;
  return n * factorial(n - 1);
}
long long int nCk(long long int n, long long int k) {
  return factorial(n) / (factorial(n - k) * factorial(k));
}
bool isPrime(long long int n) {
  for (long long int i = 2; i * i < n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long int lower(long long int n, long long int arr[], long long int low,
                    long long int high, long long int l) {
  long long int mid = low + (high - low) / 2;
  if (low > high) return -1;
  if (low == high) {
    if (arr[low] >= l)
      return low;
    else
      return -1;
  }
  if (arr[mid] >= l) {
    if (mid == 0) return mid;
    if (arr[mid - 1] >= l)
      return lower(n, arr, low, mid - 1, l);
    else
      return mid;
  } else {
    return lower(n, arr, mid + 1, high, l);
  }
}
long long int higher(long long int n, long long int arr[], long long int low,
                     long long int high, long long int r) {
  long long int mid = floor(low + (high - low) / 2);
  if (low > high) return -1;
  if (low == high) {
    if (arr[low] <= r)
      return low;
    else
      return -1;
  }
  if (arr[mid] <= r) {
    if (mid == n - 1) return mid;
    if (arr[mid + 1] <= r)
      return higher(n, arr, mid + 1, high, r);
    else
      return mid;
  } else {
    return higher(n, arr, low, mid - 1, r);
  }
}
long long int lcm(long long int n) {
  if (n == 1) return 1;
  long long int k = lcm(n - 1);
  return n * k / gcd(n, k);
}
long long int binSearch(long long int arr[], long long int low,
                        long long int high, long long int a) {
  long long int mid = floor(low + (high - low) / 2);
  if (arr[mid] == a)
    return mid;
  else if (arr[mid] < a)
    return binSearch(arr, mid + 1, high, a);
  else
    return binSearch(arr, low, mid - 1, a);
}
long long int f(long long int n) { return n * (n + 1) / 2; }
void swap(long long int arr[], long long int ind1, long long int ind2) {
  long long int tmp = arr[ind2];
  arr[ind2] = arr[ind1];
  arr[ind1] = tmp;
}
long long int power(long long int n) {
  long long int x = 1;
  for (int i = 0; i < n; i++) {
    x *= 2;
    x = x % M;
  }
  return x % M;
}
void solve(int t) {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long int ans = arr[0];
  for (int i = 1; i < n; i++) {
    ans = (ans & arr[i]);
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) solve(t);
}
