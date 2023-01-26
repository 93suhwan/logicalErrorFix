#include <bits/stdc++.h>
using namespace std;
unsigned power(unsigned long long x, unsigned long long y,
               unsigned long long p) {
  unsigned res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  auto time = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (long long tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    vector<string> str;
    string res;
    string prev;
    int flag = 1;
    for (int i = 0; i < n - 2; i++) {
      string temp;
      cin >> temp;
      if (i > 0 && prev[1] != temp[0]) {
        string last;
        last = last + prev[1];
        last += temp[0];
        str.push_back(last);
        flag = 0;
      }
      str.push_back(temp);
      prev = temp;
    }
    for (int i = 0; i < str.size(); ++i) {
      res += str[i][0];
    }
    res += str[str.size() - 1][1];
    if (flag) res += 'a';
    cout << res << endl;
  }
  return 0;
}
