#include <bits/stdc++.h>
using namespace std;
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
      long long pos = s.find(s1[i], 0);
      long long pos1 = s.find(s1[i - 1], 0);
      cnt += abs(pos - pos1);
    }
    cout << cnt << endl;
  }
}
