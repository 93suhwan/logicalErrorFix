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
  long long n, min, maxmin, integer;
  cin >> n;
  vector<long long> arr;
  for (int i = 0; i < n; i++) {
    cin >> integer;
    arr.push_back(integer);
  }
  if (n == 1)
    return arr[n - 1];
  else {
    min = *min_element(arr.begin(), arr.end());
    while (arr.size() >= 1) {
      maxmin = min;
      min = *min_element(arr.begin(), arr.end());
      if (maxmin < min) maxmin = min;
      arr.erase(find(arr.begin(), arr.end(), min));
      for (int i = 0; i < arr.size(); i++) {
        arr[i] = arr[i] - min;
        if (arr[i] < min) min = arr[i];
      }
    }
    return maxmin;
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
