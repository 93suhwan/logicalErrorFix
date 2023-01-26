#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int size = 0;
    int temp = 0, total = 0;
    for (int i = 1; i <= n; ++i) {
      size++;
      cin >> temp;
      if (size < temp) {
        total += temp - size;
        size += temp - size;
      }
    }
    cout << total << endl;
  }
}
