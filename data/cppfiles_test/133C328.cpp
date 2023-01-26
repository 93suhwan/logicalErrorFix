#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string str;
  char c = 'c';
  for (int i = 0; i < (n - 2); i++) {
    char a;
    char b;
    cin >> a >> b;
    str.push_back(a);
    str.push_back(b);
  }
  for (int i = 2; i < str.size(); i += 2) {
    if (str[i] != str[i - 1]) {
      string s;
      s.push_back(str[i - 1]);
      s.push_back(str[i]);
      str.insert(i, s);
      i -= 2;
    }
  }
  int count = 0;
  for (int i = 0; i < str.size(); i += 2) {
    if (i == 0 || i == str.size()) {
      cout << str[i] << str[i + 1];
      count += 2;
      continue;
    }
    cout << str[i + 1];
    count++;
  }
  for (int i = count; i < n; i++) {
    cout << 'a';
  }
  cout << endl;
  return;
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cout.tie(0);
  std::cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solve();
  }
  return 0;
}
