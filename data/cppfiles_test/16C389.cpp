#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s, temp;
    cin >> n >> s;
    temp = s;
    sort(temp.begin(), temp.end());
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != temp[i]) k++;
    }
    cout << k << "\n";
  }
  return 0;
}
