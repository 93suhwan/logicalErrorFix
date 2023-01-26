#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    int cnt = 1;
    for (int j = 0; j < num; j++) {
      cnt++;
      cout << cnt << " ";
    }
    cout << endl;
  }
  return 0;
}
