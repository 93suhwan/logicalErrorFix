#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans;
  while (n--) {
    string s, p;
    cin >> s >> p;
    int next[1050];
    ans = 0;
    int plen = p.size();
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < plen - 1) {
      if (k == -1 || p[j] == p[k]) {
        k++;
        j++;
        next[j] = k;
      } else {
        k = next[k];
      }
    }
    for (int i1 = 1; i1 <= s.size(); i1++) {
      string s2 = s.substr(0, i1 - 1), s3 = s.substr(0, i1);
      reverse(s3.begin(), s3.end());
      s2 += s3;
      int slen = s2.size();
      int i = 0;
      j = 0;
      while (i < slen && j < plen) {
        if (j == -1 || s2[i] == p[j]) {
          i++;
          j++;
        } else {
          j = next[j];
        }
      }
      if (j == plen) {
        ans = 1;
        cout << "Yes" << endl;
        break;
      }
    }
    if (ans == 0) {
      cout << "No" << endl;
    }
  }
  return 0;
}
