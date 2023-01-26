#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  vector<int> res;
  while (t--) {
    string abc;
    string s;
    cin >> abc >> s;
    int index = abc.find(s.at(0));
    int sum = 0;
    for (int i = 1; i < s.length(); i++) {
      int sub = index - abc.find(s.at(i));
      sum += abs(sub);
      index = abc.find(s.at(i));
    }
    res.push_back(sum);
  }
  for (int i = 0; i < res.size(); i++) {
    cout << res.at(i) << endl;
  }
}
