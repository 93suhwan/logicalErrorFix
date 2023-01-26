#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    string ke, s;
    cin >> ke >> s;
    vector<long long int> v;
    for (long long int j = 0; j < s.size(); j++) {
      for (long long int l = 0; j < ke.size(); l++) {
        if (s[j] == ke[l]) {
          v.push_back(l + 1);
          break;
        }
      }
    }
    long long int sum = 0;
    for (long long int i = 0; i < v.size() - 1; i++) {
      sum = sum + abs(v[i + 1] - v[i]);
    }
    cout << sum << endl;
  }
  return 0;
}
