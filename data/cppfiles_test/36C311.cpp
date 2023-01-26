#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
int main() {
  fastIO();
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    if (N <= 26) {
      for (int i = 1; i <= N; i++) {
        cout << char((i - 1) + 'a');
      }
      cout << "\n";
      continue;
    }
    string s = "";
    for (int i = 1; i <= (N - 2) / 2; i++) s += 'a';
    s += 'b';
    if (N % 2 == 1) s += 'c';
    for (int i = 1; i <= N / 2; i++) s += 'a';
    cout << s << "\n";
  }
}
