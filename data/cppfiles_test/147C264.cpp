#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    string str;
    cin >> str;
    int n = str.size();
    int arr[n];
    bool ans = 1;
    int e = 0;
    for (char c : str) {
      if (c == 'E') ++e;
    }
    if (e == n - 1)
      cout << "NO\n";
    else
      cout << "YES" << endl;
  }
}
