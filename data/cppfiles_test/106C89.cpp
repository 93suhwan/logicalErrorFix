#include <bits/stdc++.h>
using namespace std;
void fcode() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
int main() {
  fcode();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (int i = 2; i <= n + 1; i++) cout << i << " ";
    cout << "\n";
  }
}
