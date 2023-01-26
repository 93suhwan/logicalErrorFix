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
void prefixsum(int s[], int n, int prefixSum[]) {
  prefixSum[0] = s[0];
  for (int i = 1; i < n; i++) prefixSum[i] = prefixSum[i - 1] + s[i];
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
int binasearch(int s[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (s[mid] == x) return mid;
    if (s[mid] > x) return binasearch(s, l, mid - 1, x);
    return binasearch(s, mid + 1, r, x);
  }
  return -1;
}
bool binasearchBool(int s[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (s[mid] == x) return 1;
    if (s[mid] > x) return binasearchBool(s, l, mid - 1, x);
    return binasearchBool(s, mid + 1, r, x);
  }
  return 0;
}
bool cmp(pair<string, int>& a, pair<string, int>& b) {
  return a.second < b.second;
}
const int mxN = 2e5 + 10;
int n;
cin >> n;
cin.ignore();
string s;
cin >> s;
s[n] = '\0';
int index = 0;
for (int i = 0; i < n + 1; i++) {
  if (s[i] != '?') {
    index = i;
    break;
  }
}
for (int i = index - 1; i >= 0; i--) {
  if (i + 1 == n)
    s[i] = 'R';
  else
    s[i] = (s[i + 1] == 'R') ? 'B' : 'R';
}
for (int i = index; i < n; i++) {
  if (s[i] == '?') {
    int j = i;
    while (j < n && s[j] == '?') s[j] = (s[j - 1] == 'R') ? 'B' : 'R';
    i = j;
  }
}
cout << s << '\n';
return 0;
}
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long test;
cin >> test;
while (test--) solve();
return 0;
}
