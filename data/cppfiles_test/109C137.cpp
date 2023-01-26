#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string num;
    cin >> n;
    cin >> num;
    int sum = 0;
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
      int as = num[i] - '0';
      if (as != 0) sum = sum + as + j;
      j = 1;
    }
    cout << sum << endl;
  }
  return 0;
}
