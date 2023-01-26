#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    char s[50];
    cout << "enter the string" << endl;
    cin >> s;
    int count[26] = {0};
    int n;
    n = strlen(s);
    for (int i = 0; i < n; i++) {
      count[s[i] - 'a']++;
    }
    int tot = 0;
    for (int i = 0; i < 26; i++) {
      tot += min(2, count[i]);
    }
    tot = tot / 2;
    cout << tot << endl;
  }
  return 0;
}
