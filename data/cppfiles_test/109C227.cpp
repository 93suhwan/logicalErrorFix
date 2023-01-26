#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    long long n, i;
    cin >> n;
    string str;
    cin.ignore();
    cin >> str;
    long long len = str.length();
    long long count = 0;
    for (i = 0; i < len; i++) {
      string y = "";
      y += str[i];
      long long num = stoi(y);
      if (num > 0) {
        count += (num);
      }
      if (i != (n - 1) && num > 0) {
        count++;
      }
    }
    cout << count << "\n";
  }
  return 0;
}
