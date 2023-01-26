#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int aPowB(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = ((res) * (a));
    a = ((a) * (a));
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    stack<long long int> stick;
    queue<long long int> queen;
    deque<long long int> dan;
    pair<long long int, long long int> pool;
    set<long long int> sea;
    vector<long long int> vex;
    map<long long int, long long int> messi;
    map<long long int, long long int>::iterator it;
    map<long long int, long long int>::reverse_iterator itr;
    char ch, cchh, ccchhh;
    string s, str;
    long long int i = 0, j = 0, k = 0, ii = 0, jj = 0, kk = 0;
    long long int x = 0, y = 0, z = 0, xx = 0, yy = 0, zz = 0;
    long long int maxxi = LLONG_MIN, minni = LLONG_MAX;
    long long int ans = 0, sum = 0, n;
    cin >> n;
    long long int a[n], b[n], c[n], d[n], e[n];
    long long int aa[n], bb[n], cc[n], dd[n], ee[n];
    for (i = 0; i < n; i++) {
      cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
      aa[i] = a[i];
      bb[i] = b[i];
      cc[i] = c[i];
      dd[i] = d[i];
      ee[i] = e[i];
    }
    long long int flag = 0;
    for (i = 0; i < n - 1; i++) {
      j = i + 1;
      long long int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
      if (a[i] > a[j]) flag1 = 1;
      if (b[i] > b[j]) flag2 = 1;
      if (c[i] > c[j]) flag3 = 1;
      if (d[i] > d[j]) flag4 = 1;
      if (e[i] > e[j]) flag5 = 1;
      long long int countOfFlag = 0;
      if (flag1 == 0) countOfFlag++;
      if (flag2 == 0) countOfFlag++;
      if (flag3 == 0) countOfFlag++;
      if (flag4 == 0) countOfFlag++;
      if (flag5 == 0) countOfFlag++;
      if (countOfFlag >= 3) {
        swap(a[i], a[j]);
        swap(b[i], b[j]);
        swap(c[i], c[j]);
        swap(d[i], d[j]);
        swap(e[i], e[j]);
      }
    }
    i = n - 1;
    flag = 0;
    long long int supirior = 0;
    for (j = 0; j < n; j++) {
      if (i == j) continue;
      long long int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
      if (a[i] > a[j]) flag1 = 1;
      if (b[i] > b[j]) flag2 = 1;
      if (c[i] > c[j]) flag3 = 1;
      if (d[i] > d[j]) flag4 = 1;
      if (e[i] > e[j]) flag5 = 1;
      long long int ccountOfFlag = 0;
      if (flag1 == 0) ccountOfFlag++;
      if (flag2 == 0) ccountOfFlag++;
      if (flag3 == 0) ccountOfFlag++;
      if (flag4 == 0) ccountOfFlag++;
      if (flag5 == 0) ccountOfFlag++;
      if (ccountOfFlag >= 3) {
        supirior++;
      } else {
        break;
      }
    }
    if (supirior >= n - 1) {
      for (ii = 0; ii < n; ii++) {
        if (a[n - 1] == aa[ii] && b[n - 1] == bb[ii] && c[n - 1] == cc[ii] &&
            d[n - 1] == dd[ii] && e[n - 1] == ee[ii]) {
          cout << ii + 1 << "\n";
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) {
      cout << "-1"
           << "\n";
    }
  }
  return 0;
}
