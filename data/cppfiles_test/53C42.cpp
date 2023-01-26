#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    char c;
    cin >> n >> c;
    string temp(n, c);
    string s;
    cin >> s;
    if (s == temp)
      cout << 0;
    else {
      long long int j = -1;
      for (long long int i = 0; i < n; i++)
        if (s[i] == c) j = i;
      if (j >= n / 2)
        cout << 1 << "\n" << j + 1;
      else
        cout << 2 << "\n" << n - 1 << " " << n;
    }
    cout << "\n";
  }
}
