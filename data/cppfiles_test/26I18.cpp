#include <bits/stdc++.h>
using namespace std;
long long int countNumbers(long long int n) {
  long long int answer = 1;
  long long int min = (long)1e9 + 7;
  long long int k = 2 * n;
  for (long long int i = k; i >= 3; i--) {
    answer *= i % min;
  }
  answer = answer % min;
  return answer;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << countNumbers(n) << "\n";
  }
}
