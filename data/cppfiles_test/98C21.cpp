#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string a, b;
  char last = 0;
  int result = 0;
  int book[26]{};
  for (int x = 0; x < t; x++) {
    cin >> a >> b;
    for (int j = 0; j < 26; j++) book[a[j] % 97] = j + 1;
    for (int i = 1; i < b.size(); i++) {
      if (b[i] != b[last])
        result += abs(book[b[i] % 97] % 97 - (book[b[last] % 97] % 97));
      last = i;
    }
    cout << result << endl;
    last = 0;
    result = 0;
  }
}
