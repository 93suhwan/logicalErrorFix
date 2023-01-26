#include <bits/stdc++.h>
using namespace std;
void code() { ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0); }
int main() {
  code();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s = "1";
    while (n--) {
      cout << s << " ";
      s += '1';
    }
    cout << "\n";
  }
  return 0;
}
