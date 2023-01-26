#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    vector<char> arr;
    for (int i = 0; i < 26; i++) {
      char d;
      cin >> d;
      arr.push_back(d);
    }
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 1; i < s.size(); i++) {
      int a, b;
      for (int j = 0; j < 26; j++) {
        if (s[i - 1] == arr[j]) {
          a = j + 1;
        }
        if (s[i] == arr[j]) {
          b = j + 1;
        }
      }
      sum += abs(a - b);
    }
    cout << sum << endl;
  }
}
