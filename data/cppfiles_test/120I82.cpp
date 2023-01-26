#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> b(200002, vector<int>(20));
void calc() {
  for (int i = 1; i < 200001; i++) {
    int num = i;
    int curr = 0;
    while (num > 0) {
      b[i][curr] += num % 2;
      num /= 2;
      curr++;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, l, r;
  while (t--) {
    cin >> l >> r;
    int n = r - l;
    cout << n / 2 << endl;
  }
  return 0;
}
