#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const int M = 1e6 + 1;
vector<int> adj[M];
vector<long long> ans;
bool gone[M];
void solve() {
  long long num1, num2;
  cin >> num1 >> num2;
  long long bit1 = 0;
  long long bit2 = 0;
  long long num3 = num2 - num1 + 1;
  vector<long long> v1, v2;
  for (long long i = num1; i != 0; i = i / 2) {
    bit1 += 1;
    v1.push_back(i % 2);
  }
  for (long long i = num2; i != 0; i = i / 2) {
    bit2 += 1;
    v2.push_back(i % 2);
  }
  if (true) {
    long long val1 = 0;
    for (long long i = 0; i < v2.size() - 1; i++) {
      val1 += pow(2, i);
    }
    long long val2 = val1 - pow(2, v2.size() - 2);
    long long fans = max(num2 - val1, val1 - max(num1 - 1, val2));
    fans = max(fans, (num3 + 1) / 2);
    cout << num3 - fans << "\n";
  } else {
    if (v1.size() == 1) {
      cout << 1 << "\n";
      return;
    }
    cout << num3 - (num2 - num1) << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long freq = 1;
  cin >> freq;
  while (freq--) {
    solve();
  }
}
