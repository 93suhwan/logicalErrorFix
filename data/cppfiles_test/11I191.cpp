#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int ncr(long long int n, long long int k) {
  long long int C[n + 1][k + 1];
  long long int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  return C[n][k];
}
long long int power(long long int x, unsigned long long int y) {
  if (y == 0) return 1;
  long long int p = power(x, y / 2) % 1000000007;
  p = (p * p) % 1000000007;
  return (y % 2 == 0) ? p : (x * p) % 1000000007;
}
long long int modInverse(long long int a) {
  long long int g = gcd(a, 1000000007);
  if (g != 1)
    return -1;
  else {
    return power(a, 1000000007 - 2);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> arr;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      arr.push_back(s);
    }
    vector<vector<int>> count(n, vector<int>(5, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < arr[i].length(); j++) {
        count[i][arr[i][j] - 'a']++;
      }
    }
    int ans = INT_MIN;
    for (int i = 0; i < 5; i++) {
      int score = 0;
      int current_score = 0;
      priority_queue<int, vector<int>, greater<int>> p;
      for (int j = 0; j < n; j++) {
        if ((2 * count[j][i] - (int)arr[j].length()) > 0) {
          score++;
          current_score += count[j][i] - (arr[j].length() - count[j][i]);
        } else {
          p.push(count[j][i] - (arr[j].length() - count[j][i]));
        }
      }
      while (current_score > 0 && !p.empty()) {
        int temp = p.top();
        p.pop();
        if (current_score + temp > 0) {
          current_score += temp;
          score++;
        }
      }
      ans = max(ans, score);
    }
    cout << ans << "\n";
  }
}
