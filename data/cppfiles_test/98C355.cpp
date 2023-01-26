#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
vector<int> vv[N];
int main() {
  int p;
  int aa, bb, cc, dd, ee, ff, gg;
  cin >> p;
  while (p--) {
    string ss, s;
    vector<int> v;
    cin >> ss;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < ss.size(); j++) {
        if (ss[j] == s[i]) {
          v.push_back(j + 1);
          break;
        }
      }
    }
    int sum = 0;
    for (int i = 1; i < v.size(); i++) {
      sum = abs(v[i - 1] - v[i]) + sum;
    }
    cout << sum << endl;
  }
}
