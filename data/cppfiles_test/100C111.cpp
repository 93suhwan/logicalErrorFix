#include <bits/stdc++.h>
using namespace std;
int result() {
  int result = 0, len, i;
  string keyboard, word;
  cin >> keyboard >> word;
  len = word.length();
  i = len - 1;
  for (int i = len - 1; i > 0; i--) {
    int f = keyboard.find(word[i]) + 1;
    int g = keyboard.find(word[i - 1]) + 1;
    result += abs(f - g);
  }
  return result;
}
int minimum() {
  long long n, min, integer;
  cin >> n;
  vector<long long> arr;
  for (int i = 0; i < n; i++) {
    cin >> integer;
    arr.push_back(integer);
  }
  if (n == 1)
    return arr[0];
  else {
    sort(arr.begin(), arr.end());
    long long min = arr[0];
    for (int i = 1; i < n; i++) {
      min = max(min, arr[i] - arr[i - 1]);
    }
    return min;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << minimum() << endl;
  }
  return 0;
}
