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
  int count = 0;
  string str2;
  for (int i = 0; i < str.size(); i += 2) {
    if (i > 1 && str[i] != str[i - 1]) {
      str2.push_back(str[i]);
      continue;
    }
    if (i == 0) {
      str2.push_back(str[i]);
      str2.push_back(str[i + 1]);
      continue;
    }
    if (i == str.size() - 2) {
      str2.push_back(str[i]);
      str2.push_back(str[i + 1]);
      break;
    }
    str2.push_back(str[i + 1]);
  }
  for (int i = str2.size(); i < n; i++) {
    str2.push_back('a');
  }
  cout << str2 << endl;
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
