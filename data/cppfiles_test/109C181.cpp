#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n;
  cin >> n;
  int sum = 0;
  bool isLastZero = false;
  for (int i = 0; i < n; ++i) {
    char sym;
    cin >> sym;
    string sd = (string) "" + sym;
    int num = stoi(sd);
    if (i == n - 1) isLastZero = (num == 0);
    if (num == 0) continue;
    sum += num + 1;
  }
  if (!isLastZero) sum--;
  return sum;
}
int main() {
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";
}
