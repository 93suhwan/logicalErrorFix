#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int _;
  cin >> _;
  while (_--) {
    long long n;
    cin >> n;
    char k;
    cin >> k;
    string s;
    cin >> s;
    long long Count = count(s.begin(), s.end(), k);
    bool Tr = n == Count;
    if (Tr) {
      cout << "0\n";
      continue;
    }
    for (int i = s.size(); i > s.size() / 2; i--) {
      if (s[i - 1] == k) {
        cout << 1 << '\n' << i << '\n';
        goto fuck;
      }
    }
    cout << 2 << '\n' << s.size() << " " << s.size() - 1 << '\n';
  fuck:;
  }
  return 0;
}
