#include <bits/stdc++.h>
using namespace std;
bool Prime(int a) {
  if (a == 1) return true;
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
      if (s[i] == 'N') count++;
    count == 1 ? cout << "NO" : cout << "YES";
    cout << endl;
  }
}
