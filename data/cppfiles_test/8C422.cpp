#include <bits/stdc++.h>
using namespace std;
void input() {
  freopen("input.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 3 == 0)
      cout << n / 3 << " " << n / 3 << endl;
    else if (n % 3 == 1)
      cout << (n / 3) + 1 << " " << n / 3 << endl;
    else
      cout << n / 3 << " " << (n / 3) + 1 << endl;
  }
}
