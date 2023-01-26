#include <bits/stdc++.h>
using namespace std;
const long long N = 200010;
long long n, a[N];
signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    string n;
    long long k;
    cin >> n >> k;
    while (true) {
      set<char> s;
      for (long long i = 0; i < n.size(); i++) s.insert(n[i]);
      if (s.size() <= k) {
        cout << n << endl;
        break;
      } else {
        s.clear();
        long long pos = 0;
        while (true) {
          s.insert(n[pos]);
          if (s.size() > k) {
            while (n[pos] == '9') pos--;
            n[pos]++;
            for (long long i = pos + 1; i < n.size(); i++) n[i] = '0';
            break;
          }
          pos++;
        }
      }
    }
  }
  return 0;
}
