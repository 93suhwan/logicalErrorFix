#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, temp;
    cin >> s;
    temp = s;
    sort(temp.begin(), temp.end());
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != temp[i]) c++;
    }
    cout << c;
    cout << endl;
  }
}
