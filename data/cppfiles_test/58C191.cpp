#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  int temp;
  while (b > 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
string to_binary(int x) {
  string s;
  while (x > 0) {
    s += (x % 2 ? '1' : '0');
    x /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
int binarySearch(int arr[], int l, int h, int x) {
  if (h >= l) {
    int mid = l + (h - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, h, x);
  }
  return -1;
}
long long power(int A, long long B, int C) {
  if (A == 0) return 0;
  if (B == 0) return 1;
  long y;
  if (B % 2 == 0) {
    y = power(A, B / 2, C);
    y = (y * y) % C;
  } else {
    y = A % C;
    y = (y * power(A, B - 1, C) % C) % C;
  }
  return ((y) % C);
}
void yes() {
  cout << "YES"
       << "\n";
}
void no() {
  cout << "NO"
       << "\n";
}
long long f(long long a) {
  long long res[] = {a, 1, a + 1, 0};
  return res[a % 4];
}
long long getXor(long long a, long long b) { return f(b) ^ f(a - 1); }
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, s1;
    cin >> s >> s1;
    bool flag = true;
    if (s1[n - 1] == '1') flag = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && s1[i] == '1') flag = false;
    }
    if (flag)
      yes();
    else
      no();
  }
  return 0;
  ;
}
