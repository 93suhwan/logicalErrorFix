#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<long long> anses;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    long long count = 0;
    string s1;
    cin >> s1;
    int prevIndex = s.find(s1[0]);
    for (int j = 0; j < s1.length(); j++) {
      int index = s.find(s1[j]);
      count += abs(prevIndex - index);
      prevIndex = index;
    }
    anses.push_back(count);
  }
  for (int i = 0; i < t; i++) cout << anses[i] << endl;
}
