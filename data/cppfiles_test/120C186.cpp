#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<vector<int>> table(200001 + 1, vector<int>(20, 0));
  for (int i = 0; i <= 200001; i++) {
    int temp = i, counter = 0;
    while (temp > 0) {
      table[i][counter] = temp % 2;
      temp /= 2;
      counter++;
    }
  }
  for (int i = 0; i < 20; i++) {
    int sum = 0;
    for (int j = 0; j <= 200001; j++) {
      sum += table[j][i];
      table[j][i] = sum;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int answer = 0;
    for (int i = 0; i < 20; i++) {
      answer = max(answer, table[r][i] - table[l - 1][i]);
    }
    cout << r - l + 1 - answer << "\n";
  }
  return 0;
}
