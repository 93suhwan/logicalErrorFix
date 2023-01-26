#include <bits/stdc++.h>
using namespace std;
int t;
int n;
char candles[100001];
char desired[100001];
int candle_count;
int desired_count;
int matches;
int alt_matches;
int result;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    candle_count = 0;
    desired_count = 0;
    matches = 0;
    for (int i = 0; i < n; i++) {
      cin >> candles[i];
      candle_count += candles[i] - '0';
    }
    for (int i = 0; i < n; i++) {
      cin >> desired[i];
      desired_count += desired[i] - '0';
      matches += desired[i] == candles[i];
    }
    alt_matches = n - matches + 1;
    if (desired_count == (n - candle_count + 1)) {
      if (desired_count == candle_count) {
        result = min(matches, n - matches);
      } else {
        result = matches;
      }
    } else if (desired_count == candle_count) {
      result = n - matches;
    } else {
      result = -1;
    }
    cout << result << endl;
  }
}
