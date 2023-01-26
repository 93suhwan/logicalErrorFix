#include <bits/stdc++.h>
using namespace std;
void solution() {
  long long int n, m, a, b, c, d, p, q, cnt = 0, ct = 0, sum = 0, ans = 0;
  cin >> n >> a;
  cin >> m >> b;
  string s1 = to_string(n);
  string s2 = to_string(m);
  long long int sz1 = s1.size();
  long long int sz2 = s2.size();
  if (sz1 > sz2) {
    long long int sz = sz1 - sz2;
    b -= sz;
    if (a > b)
      cout << ">" << endl;
    else if (b > a)
      cout << "<" << endl;
    else {
      for (long long int i = 0; i < sz2; i++) {
        if (s1[i] > s2[i]) {
          cout << ">" << endl;
          return;
        } else if (s2[i] > s1[i]) {
          cout << "<" << endl;
          return;
        }
      }
      cout << "=" << endl;
    }
  } else if (sz2 > sz1) {
    long long int sz = sz2 - sz1;
    a -= sz;
    if (a > b)
      cout << ">" << endl;
    else if (b > a)
      cout << "<" << endl;
    else {
      for (long long int i = 0; i < sz1; i++) {
        if (s1[i] > s2[i]) {
          cout << ">" << endl;
          return;
        } else if (s2[i] > s1[i]) {
          cout << "<" << endl;
          return;
        }
      }
      cout << "=" << endl;
    }
  } else {
    if (n > m)
      cout << ">" << endl;
    else if (m > n)
      cout << "<" << endl;
    else
      cout << "=" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
