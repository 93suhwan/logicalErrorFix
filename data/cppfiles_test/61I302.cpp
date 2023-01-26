#include <bits/stdc++.h>
using namespace std;
int binexpomod(int a, int b, int m) {
  int res = 1;
  a %= m;
  b %= (m - 1);
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
int binexpo(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void prefixsum(int arr[], int n, int prefixSum[]) {
  prefixSum[0] = arr[0];
  for (int i = 1; i < n; i++) prefixSum[i] = prefixSum[i - 1] + arr[i];
}
bool ispowerof2(int n) {
  if (n == 0) return 0;
  while (n != 1) {
    if (n % 2 != 0) return 0;
    n = n / 2;
  }
  return 1;
}
int nextpowof2(int n) {
  n--;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n++;
  return n;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void swap(int* a, int* b) { *a ^= *b ^= *a ^= *b; }
string binaryof(int n) {
  string s = bitset<64>(n).to_string();
  const auto loc1 = s.find('1');
  if (loc1 != string::npos) return s.substr(loc1);
  return "0";
}
int binasearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binasearch(arr, l, mid - 1, x);
    return binasearch(arr, mid + 1, r, x);
  }
  return -1;
}
bool binasearchBool(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return 1;
    if (arr[mid] > x) return binasearchBool(arr, l, mid - 1, x);
    return binasearchBool(arr, mid + 1, r, x);
  }
  return 0;
}
bool cmp(pair<string, int>& a, pair<string, int>& b) {
  return a.second < b.second;
}
const int mxN = 2e5 + 10;
s[i] = 'R';
int cnt = 0;
for (int i = 0; i < n - 1; i++) {
  if (s[i] == s[i + 1]) cnt++;
}
return cnt;
}
int blue(string s, int n, int i) {
  s[i] = 'B';
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) cnt++;
  }
  return cnt;
}
bool mini(string s, int n, int i) {
  int x = blue(s, n, i);
  int y = red(s, n, i);
  return (x > y);
}
int solve() {
  int n;
  cin >> n;
  cin.ignore();
  string s;
  cin >> s;
  if (n == 1) {
    if (s[0] == '?') {
      cout << "B\n";
    } else
      cout << s << '\n';
  } else {
    for (int i = 0; i < n; i++) {
      if (i == n - 1 and s[i] == '?') {
        s[i] = ((s[i - 1] == 'B') ? 'R' : 'B');
      }
      if (s[i] == '?') {
        bool x = mini(s, n, i);
        if (x)
          s[i] = 'R';
        else
          s[i] = 'B';
      }
    }
    cout << s << '\n';
  }
  return 0;
}
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long test;
cin >> test;
while (test--) solve();
return 0;
}
