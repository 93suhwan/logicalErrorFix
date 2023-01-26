#include <bits/stdc++.h>
int a[100005];
using namespace std;
int main() {
  int res, sum;
  int Q;
  cin >> Q;
  while (Q--) {
    res = 0;
    sum = 0;
    string s;
    cin >> s;
    memset(a, 0, sizeof a);
    for (int i = 0; i < s.size(); i++) {
      a[s[i]]++;
    }
    for (int i = 97; i <= 97 + 30; i++) {
      if (a[i] > 1) {
        res++;
        sum += a[i];
      }
    }
    cout << res + (s.size() - sum) / 2 << endl;
  }
  return 0;
}
