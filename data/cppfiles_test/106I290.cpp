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
    int i = 1;
    while (n--) {
      cout << i << " ";
      i += 2;
    }
    cout << "\n";
  }
  return 0;
}
