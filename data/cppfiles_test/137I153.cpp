#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
string dtob(long long x) {
  string s = "";
  while (x) {
    if (x & 1) {
      s += '1';
    } else {
      s += '0';
    }
    x >>= 1;
  }
  reverse(s.begin(), s.end());
  return s;
}
string removeLeadingzeros(string s) {
  const regex pattern("^0+(?!$)");
  s = regex_replace(s, pattern, "");
  return s;
}
bool ifposible(string s, string p) {
  if (s.length() > p.length()) {
    return false;
  }
  bool check = true;
  if (p.find(s) != string::npos) {
    long long x1 = p.find(s);
    for (long long i = 0; i < x1; i++) {
      if (p[i] == '0') {
        check = false;
        break;
      }
    }
    if (check) {
      for (long long i = x1 + s.length(); i < p.length(); i++) {
        if (p[i] == '0') {
          check = false;
          break;
        }
      }
    }
  } else {
    check = false;
  }
  if (check) {
    return true;
  } else {
    return false;
  }
}
void HareKrishna() {
  long long x, y;
  string s = "", p = "";
  cin >> x >> y;
  if (x == y) {
    cout << "YES" << endl;
    return;
  }
  long long t1 = ceil(log2(x));
  long long t2 = ceil(log2(y));
  if ((x & 1 && t2 < t1) || y % 2 == 0) {
    cout << "NO" << endl;
    return;
  }
  s = dtob(x);
  p = dtob(y);
  if (p.length() == s.length() && x % 2 == 0) {
    cout << "NO" << endl;
    return;
  }
  string s1 = s;
  s1 += '0';
  reverse(s1.begin(), s1.end());
  s1 = removeLeadingzeros(s1);
  string s4 = s1;
  reverse(s4.begin(), s4.end());
  string s2 = s;
  s2 += '1';
  string s3 = s2;
  reverse(s2.begin(), s2.end());
  if (ifposible(s1, p)) {
    cout << "YES" << endl;
    return;
  }
  if (ifposible(s2, p)) {
    cout << "YES" << endl;
    return;
  }
  if (ifposible(s3, p)) {
    cout << "YES" << endl;
    return;
  }
  if (ifposible(s4, p)) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    HareKrishna();
  }
  return 0;
}
