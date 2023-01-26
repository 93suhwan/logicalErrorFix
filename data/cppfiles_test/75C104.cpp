#include <bits/stdc++.h>
using namespace std;
const long long base = 1e9 + 7;
const long long MAX_N = 2e6 + 1;
string getWinner(int i) {
  if (i % 2) return "Bob";
  return "Alice";
}
void Solves() {
  long long n;
  cin >> n;
  long long a[n + 2];
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<long long> left;
  vector<long long> right;
  for (int i = 1; i <= n; i++) {
    if (i == 1 || a[i] > a[i - 1])
      left.push_back(a[i]);
    else
      break;
  }
  for (int i = n; i >= 1; i--) {
    if (i == n || a[i] > a[i + 1])
      right.push_back(a[i]);
    else
      break;
  }
  reverse(left.begin(), left.end());
  reverse(right.begin(), right.end());
  long long ans = 0;
  while (1) {
    long long l = left.back();
    long long r = right.back();
    if (l > r) {
      if (left.size() % 2 == 1) {
        cout << getWinner(ans);
        break;
      }
      right.pop_back();
      ans++;
      ans %= 2;
    }
    if (r > l) {
      if (right.size() % 2 == 1) {
        cout << getWinner(ans);
        break;
      }
      left.pop_back();
      ans++;
      ans %= 2;
    }
    if (l == r) {
      if (left.size() % 2 == 1 || right.size() % 2 == 1) {
        cout << getWinner(ans);
      } else {
        cout << getWinner((ans + 1) % 2);
      }
      break;
    }
  }
}
int main() { Solves(); }
