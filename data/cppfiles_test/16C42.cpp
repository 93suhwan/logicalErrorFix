#include <bits/stdc++.h>
using namespace std;
void mysol() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    string strcopy = str;
    sort(str.begin(), str.end());
    long cnt = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] != strcopy[i]) cnt++;
    }
    cout << cnt << "\n";
  }
}
int main() {
  mysol();
  return 0;
}
