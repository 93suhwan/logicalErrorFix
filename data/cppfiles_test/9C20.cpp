#include <bits/stdc++.h>
using namespace std;
int taking_no_of_testcases() {
  int t;
  cin >> t;
  return t;
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  cout.tie(NULL);
  int testcases = taking_no_of_testcases();
  while (testcases--) {
    string s;
    cin >> s;
    int a[s.size()];
    for (int i = 0; i < s.size(); i++) {
      a[i] = 0;
    }
    int i = 0, count = 0, j = 0;
    sort(s.begin(), s.end());
    while (i < s.size()) {
      count = 0;
      char c = s[i];
      while (c == s[i]) {
        count++;
        i++;
      }
      if (count > 2) {
        a[j++] = 2;
      } else {
        a[j++] = count;
      }
    }
    long long sum = 0;
    for (int i = 0; i < s.size(); i++) {
      sum += a[i];
    }
    cout << sum / 2 << endl;
  }
  return 0;
}
