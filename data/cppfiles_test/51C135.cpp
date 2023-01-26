#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
int INFH = 2e9 + 10;
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
int binexp(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binexp(a, b / 2);
  if (b & 1)
    return a * res * res;
  else
    return res * res;
}
int factorial(int i) { return i ? factorial(i - 1) * i : 1; }
bool prime(long long n) {
  if (n <= 2) return false;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int di(long long n) {
  long long sum = 0;
  while (n > 0) {
    n /= 10;
    sum++;
  }
  return sum;
}
long long M = 1e9 + 7;
int smallest_divisor(int n) {
  int i;
  for (i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      return i;
    }
  }
  return n;
}
void solved() {
  long long n;
  cin >> n;
  cout << -(n - 1) << " " << n << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solved();
  }
}
