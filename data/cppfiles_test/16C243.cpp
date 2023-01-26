#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string temp = s;
    sort(s.begin(), s.end());
    int count = 0;
    for (int i = 0; i < s.size(); i++)
      if (s[i] != temp[i]) count++;
    cout << count << "\n";
  }
}
