#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long int N = 2e5 + 10;
const long long int M = 2e5 + 1;
const long long int big = 1e18;
const long long int hsh2 = 1964325029;
const long long mod = 1e9 + 7;
const long double EPS = 1e-14;
const long long int block = 1e7;
const long long int shift = 2e3;
long long int a, b, c, d, e[3000001];
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int findGCD(long long int arr[], int n) {
  long long int result = arr[0];
  for (int i = 1; i < n; i++) {
    result = gcd(arr[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
long long int power(long long int x, long long int y) {
  if (y == 0) return 1;
  long long int temp = power(x, y / 2);
  if (y % 2 == 0)
    return (temp * temp) % mod;
  else
    return (((x * temp) % mod) * temp) % mod;
}
int small(int x, int y, int z) {
  long long int smallest = INT_MAX;
  if (x < smallest) {
    smallest = x;
  }
  if (y < smallest) {
    smallest = y;
  }
  if (z < smallest) {
    smallest = z;
  }
  return smallest;
}
void increment(int &cur_x, int &cur_y, int m) {
  if (cur_x == m && cur_y % 2 == 1) {
    cur_y++;
  } else if (cur_x == 1 && cur_y % 2 == 0) {
    cur_y++;
  } else {
    if (cur_y % 2 == 1) {
      cur_x++;
    } else {
      cur_x--;
    }
  }
}
int char_to_int(char a) { return (int)a - 48; }
int diff(char a, char b) { return min(abs(a - b), 26 - abs(a - b)); }
int counter(int count, int arr[], int p, int n, int dir) {
  int value = 0;
  int temp[n];
  for (int i = 0; i < n; i++) {
    temp[i] = arr[i];
  }
  while (count != 0) {
    if (temp[p] == 1) {
      count--;
      temp[p] = 0;
    }
    if (count == 0) {
      break;
    }
    if (dir == 1 && p == n / 2 - 1) {
      dir = -1;
    }
    if (dir == -1 && p == 0) {
      dir = 1;
    }
    p += dir;
    value++;
  }
  return value;
}
void solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  int cur = 0;
  if ((t[0] == 'a' && t[1] == 'b') || (t[0] == 'a' && t[2] == 'b') ||
      (t[1] == 'a' && t[2] == 'b')) {
    cur = 1;
  }
  int n = s.length();
  char arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = s[i];
  }
  sort(arr, arr + n);
  string out = "";
  if (cur == 0) {
    for (int i = 0; i < n; i++) {
      out += arr[i];
    }
  }
  if (cur == 1) {
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] != 'a') {
        j = i;
        break;
      }
      out += arr[i];
    }
    for (int i = j; i < n; i++) {
      out = arr[i] + out;
    }
  }
  cout << out << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int t;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
  }
  return 0;
}
