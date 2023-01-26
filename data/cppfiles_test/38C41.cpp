#include <bits/stdc++.h>
const long long _INF = 1e18;
const int INF = 1e9;
using namespace std;
int T;
void solved() {
  long long n = 0;
  cin >> n;
  if (n % 2 == 1) n++;
  if (n <= 6)
    cout << 15 << "\n";
  else
    cout << n * 5 / 2 << "\n";
}
int main() {
  setbuf(stdout, NULL);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  for (int i = 0; i < (T); i++) {
    solved();
  }
}
