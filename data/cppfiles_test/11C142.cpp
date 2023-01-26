#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
bool isprime(long long num) {
  if (num == 1) return 0;
  if (num == 2 || num == 3) return 1;
  if (num % 6 != 1 && num % 6 != 5) return 0;
  int tmp = sqrt(num);
  for (long long i = 5; i <= tmp; i += 6)
    if (num % i == 0 || num % (i + 2) == 0) return 0;
  return 1;
}
long long binpow(long long a, long long b) {
  if (a == 0 && b == 0) return 1;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
struct node {
  int top;
  int bottom;
  int num;
  bool operator<(node a) {
    if (top != a.top) return top < a.top;
    return num < a.num;
  }
};
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator+(const point a) { return point(x + a.x, y + a.y); }
  point operator-(const point a) { return point(x - a.x, y - a.y); }
};
bool cmp0(vector<int> a, vector<int> b) {
  return (a[5] - a[0] - a[0]) < (b[5] - b[0] - b[0]);
}
bool cmp1(vector<int> a, vector<int> b) {
  return (a[5] - a[1] - a[1]) < (b[5] - b[1] - b[1]);
}
bool cmp2(vector<int> a, vector<int> b) {
  return (a[5] - a[2] - a[2]) < (b[5] - b[2] - b[2]);
}
bool cmp3(vector<int> a, vector<int> b) {
  return (a[5] - a[3] - a[3]) < (b[5] - b[3] - b[3]);
}
bool cmp4(vector<int> a, vector<int> b) {
  return (a[5] - a[4] - a[4]) < (b[5] - b[4] - b[4]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    vector<vector<int>> num;
    string s;
    cin >> n;
    int re = 0;
    for (int i = 0; i < n; ++i) {
      vector<int> num2 = {0, 0, 0, 0, 0, 0};
      cin >> s;
      num2[5] = s.size();
      for (int j = 0; j < s.size(); ++j) {
        num2[s[j] - 'a']++;
      }
      num.push_back(num2);
    }
    sort(num.begin(), num.end(), cmp0);
    int th = 0, z = 0, r = 0;
    for (int i = 0; i < n; ++i) {
      th += num[i][0];
      z += num[i][5] - num[i][0];
      if (th > z)
        r++;
      else {
        re = max(r, re);
        break;
      }
    }
    re = max(r, re);
    th = 0, z = 0, r = 0;
    sort(num.begin(), num.end(), cmp1);
    for (int i = 0; i < n; ++i) {
      th += num[i][1];
      z += num[i][5] - num[i][1];
      if (th > z)
        r++;
      else {
        re = max(r, re);
        break;
      }
    }
    re = max(r, re);
    th = 0, z = 0, r = 0;
    sort(num.begin(), num.end(), cmp2);
    for (int i = 0; i < n; ++i) {
      th += num[i][2];
      z += num[i][5] - num[i][2];
      if (th > z)
        r++;
      else {
        re = max(r, re);
        break;
      }
    }
    re = max(r, re);
    th = 0, z = 0, r = 0;
    sort(num.begin(), num.end(), cmp3);
    for (int i = 0; i < n; ++i) {
      th += num[i][3];
      z += num[i][5] - num[i][3];
      if (th > z)
        r++;
      else {
        re = max(r, re);
        break;
      }
    }
    re = max(r, re);
    th = 0, z = 0, r = 0;
    sort(num.begin(), num.end(), cmp4);
    for (int i = 0; i < n; ++i) {
      th += num[i][4];
      z += num[i][5] - num[i][4];
      if (th > z)
        r++;
      else {
        re = max(r, re);
        break;
      }
    }
    re = max(r, re);
    cout << re << endl;
  }
  return 0;
}
