#include <bits/stdc++.h>
using namespace std;
int solve(string &str, int t) {
  string temp = str;
  int flag = 0;
  sort(temp.begin(), temp.end());
  for (int i = 0; i < t; i++) {
    if (str[i] != temp[i]) {
      flag++;
    }
  }
  cout << t - flag << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n) {
    int t;
    cin >> t;
    string str;
    cin >> str;
    solve(str, t);
    n--;
  }
  return 0;
}
