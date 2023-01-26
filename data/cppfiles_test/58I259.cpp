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
int count(string s, int n) {
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') x++;
  }
  return x;
}
int xorr(string s, string t, int n) {
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i])
      x++;
    else if (s[i] == '1' && t[i] == '1')
      x++;
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char a[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    vector<string> v;
    for (int i = 0; i < 5; i++) {
      string s;
      for (int j = 0; j < n; j++) {
        s += a[j][i];
      }
      v.push_back(s);
    }
    bool flag = false;
    int x = n / 2;
    for (int i = 0; i < 5; i++) {
      string s;
      s += v[i];
      for (int j = i + 1; j < 5; j++) {
        string s1;
        s1 += v[j];
        if (count(s, n) >= x && count(s1, n) >= x) {
          if (xorr(s, s1, n) == n) flag = true;
        }
      }
    }
    if (flag)
      yes();
    else
      no();
  }
  return 0;
  ;
}
