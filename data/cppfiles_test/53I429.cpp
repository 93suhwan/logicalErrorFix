#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    char a;
    cin >> a;
    string s;
    cin >> s;
    long long ss = s.size();
    bool flag = true;
    long long k, c = 0;
    unordered_map<int, int> m;
    for (long long i = 1; i <= ss; i++) {
      if (s[i - 1] == a) {
        c++;
        if (flag) {
          k = i;
          flag = false;
        }
        m[i]++;
      }
    }
    if (c == ss) {
      cout << 0 << endl;
      continue;
    }
    long long j = ss / k;
    bool fl = true;
    for (long long i = 1; i <= j; i++) {
      if (m.find(k * i) == m.end()) {
        fl = false;
      }
    }
    if (fl) {
      cout << 1 << endl;
      cout << k << endl;
    } else {
      cout << 2 << endl;
      cout << ss << " " << ss - 1 << endl;
    }
  }
}
