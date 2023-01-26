#include <bits/stdc++.h>
using namespace std;
int Int10(int x) {
  int result = 1;
  while (result * 10 <= x) result *= 10;
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  for (int q = 0; q < test; q += 1) {
    int s, n;
    cin >> s >> n;
    while (n > 0) {
      int best = Int10(s - n + 1);
      if (n == 1) best = s;
      s -= best;
      n -= 1;
      cout << best << " ";
    }
    cout << "\n";
  }
}
