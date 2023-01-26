#include <bits/stdc++.h>
using namespace std;
void solve(long long nn) {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES";
    return;
  }
  vector<long long> v;
  long long cnt1 = 0;
  long long cnt2 = 0;
  long long kk = 0;
  while (x) {
    v.push_back(x % 2);
    x /= 2;
  }
  reverse(v.begin(), v.end());
  while (v.back() == 0) {
    kk++;
    v.pop_back();
  }
  vector<long long> vv;
  vector<long long> vvv;
  vvv = v;
  reverse(vvv.begin(), vvv.end());
  while (y) {
    if (y % 2 == 0) cnt2++;
    vv.push_back(y % 2);
    y /= 2;
  }
  for (long long x : vvv) {
    if (x == 0) cnt1++;
  }
  reverse(vv.begin(), vv.end());
  vector<long long> v4 = vv;
  reverse(v4.begin(), v4.end());
  if (v.size() > vv.size()) {
    cout << "NO"
         << "\n";
    return;
  }
  for (long long i = 0; i < vv.size(); i++) {
    long long flag = 0;
    for (long long j = 0; j < v.size(); j++) {
      if (vv[i + j] != v[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      long long m = 0;
      for (long long k = i + v.size(); k < vv.size(); k++) {
        if (vv[k] == 0)
          m++;
        else
          break;
      }
      if (cnt2 <= (cnt1 + m) and m <= kk) {
        cout << "YES"
             << "\n";
        return;
      }
    }
    flag = 0;
    for (long long j = 0; j < vvv.size(); j++) {
      if (vv[i + j] != vvv[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0 and cnt2 == cnt1) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  for (long long i = 0; i < v4.size(); i++) {
    long long flag = 0;
    for (long long j = 0; j < v.size(); j++) {
      if (v4[i + j] != v[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      long long m = 0;
      for (long long k = i + v.size(); k < v4.size(); k++) {
        if (v4[k] == 0)
          m++;
        else
          break;
      }
      if (cnt2 <= (cnt1 + m) and m <= kk) {
        cout << "YES"
             << "\n";
        return;
      }
    }
    flag = 0;
    for (long long j = 0; j < vvv.size(); j++) {
      if (v4[i + j] != vvv[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0 and cnt2 == cnt1) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  cout << "NO"
       << "\n";
  return;
}
int main() {
  std::cout << std::fixed;
  std::cout << std::setprecision(15);
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  t = 1;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
