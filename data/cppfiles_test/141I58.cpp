#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    long long int i = s1.length() - 1, j = s2.length() - 1;
    long long int flag = 1;
    vector<long long int> v;
    while (i >= 0) {
      if (j < 0) {
        flag = 0;
        break;
      }
      if (s2[j] < s1[i]) {
        if (j <= 0 ||
            ((s2[j - 1] - '0') * 10 + (s2[j] - '0') - (s1[i] - '0')) >= 10) {
          flag = 0;
          break;
        }
        v.push_back((s2[j - 1] - '0') * 10 + (s2[j] - '0') - (s1[i] - '0'));
        j = j - 2;
        i--;
      } else {
        v.push_back(s2[j] - s1[i]);
        j--;
        i--;
      }
    }
    for (long long int k = 0; k <= j; k++) {
      v.push_back(s2[k] - '0');
    }
    reverse(v.begin(), v.end());
    if (flag == 0)
      cout << -1;
    else {
      long long int i = 0;
      while (v[i] == 0) i++;
      for (long long int j = i; j < v.size(); j++) cout << v[j];
    }
    cout << endl;
  }
  return 0;
}
