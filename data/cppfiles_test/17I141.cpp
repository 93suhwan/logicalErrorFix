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
    vector<long long int>::iterator it;
    map<long long int, long long int>::reverse_iterator itr;
    char ch, cchh, ccchhh;
    string s, str;
    long long int i = 0, j = 0, k = 0, ii = 0, jj = 0, kk = 0;
    long long int x = 0, y = 0, z = 0, xx = 0, yy = 0, zz = 0;
    long long int maxxi = LLONG_MIN, minni = LLONG_MAX;
    long long int ans = 0, sum = 0, n;
    cin >> n;
    pair<long long int, long long int> a[n], b[n], c[n], d[n], e[n];
    long long int aa[n], bb[n], cc[n], dd[n], ee[n];
    for (i = 0; i < n; i++) {
      cin >> a[i].first >> b[i].first >> c[i].first >> d[i].first >> e[i].first;
      a[i].second = i + 1;
      b[i].second = i + 1;
      c[i].second = i + 1;
      d[i].second = i + 1;
      e[i].second = i + 1;
      aa[i] = a[i].first;
      bb[i] = b[i].first;
      cc[i] = c[i].first;
      dd[i] = d[i].first;
      ee[i] = e[i].first;
    }
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    sort(d, d + n);
    sort(e, e + n);
    vex.push_back(a[0].second);
    vex.push_back(b[0].second);
    vex.push_back(c[0].second);
    vex.push_back(d[0].second);
    vex.push_back(e[0].second);
    if (n > 1) {
      vex.push_back(a[1].second);
      vex.push_back(b[1].second);
      vex.push_back(c[1].second);
      vex.push_back(d[1].second);
      vex.push_back(e[1].second);
    }
    if (n > 2) {
      vex.push_back(a[2].second);
      vex.push_back(b[2].second);
      vex.push_back(c[2].second);
      vex.push_back(d[2].second);
      vex.push_back(e[2].second);
    }
    long long int flag = 0;
    for (it = vex.begin(); it != vex.end(); it++) {
      i = *it - 1;
      long long int supirior = 0;
      for (j = 0; j < n; j++) {
        if (i == j) continue;
        long long int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
        if (aa[i] > aa[j]) flag1 = 1;
        if (bb[i] > bb[j]) flag2 = 1;
        if (cc[i] > cc[j]) flag3 = 1;
        if (dd[i] > dd[j]) flag4 = 1;
        if (ee[i] > ee[j]) flag5 = 1;
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
        cout << i + 1 << "\n";
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "-1"
           << "\n";
    }
  }
  return 0;
}
