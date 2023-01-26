#include <bits/stdc++.h>
using namespace std;
bool ok(long long x, long long n) { return (x * x + x) / 2 > n; }
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string s1;
    cin >> s1;
    long long cnt = 0;
    for (int i = 1; i < s1.length(); i++) {
      long long pos = s.find(s1[i], 1);
      long long pos1 = s.find(s1[i - 1], 1);
      cnt += abs(pos - pos1);
    }
    cout << cnt << endl;
  }
}
