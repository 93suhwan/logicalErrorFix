#include <bits/stdc++.h>
using namespace std;
static const size_t MAX_NUMBERS_COUNT = 1e5;
static const double EPS = 0.00000001;
enum EOperation { INC, DEC };
long long CalcPairsCount(long long n) { return (n + 1) * n / 2; }
int CountEqualNumbers(int pos, const vector<long long>& numbers,
                      EOperation op) {
  int counter = 1;
  switch (op) {
    case INC: {
      for (int i = pos + 1; i < numbers.size() && numbers[i] == numbers[pos];
           ++i) {
        counter++;
      }
    }
    case DEC: {
      for (int i = pos - 1; i > 0 && numbers[i] == numbers[pos]; --i) {
        counter++;
      }
    }
  }
  return counter;
}
int main() {
  vector<long long> numbers;
  numbers.reserve(MAX_NUMBERS_COUNT);
  int t;
  cin >> t;
  long long n, value, counter;
  double sum, k;
  for (int packNumber = 0; packNumber < t; ++packNumber) {
    cin >> n;
    counter = 0;
    sum = 0;
    numbers.clear();
    for (int i = 0; i < n; ++i) {
      cin >> value;
      numbers.push_back(value);
      sum += value;
    }
    k = sum / n;
    sort(numbers.begin(), numbers.end());
    int left = 0;
    int right = n - 1;
    long long leftNumbersCount, rightNumbersCount;
    while (left < right) {
      double newK = (sum - numbers[left] - numbers[right]) / (n - 2);
      if (abs(newK - k) < EPS) {
        if (numbers[left] == numbers[right]) {
          counter += CalcPairsCount(right - left);
          break;
        }
        leftNumbersCount = CountEqualNumbers(left, numbers, INC);
        left += leftNumbersCount;
        rightNumbersCount = CountEqualNumbers(right, numbers, DEC);
        right + rightNumbersCount;
        counter += leftNumbersCount * rightNumbersCount;
      } else {
        if (newK > k) {
          ++left;
        } else if (newK < k) {
          --right;
        }
      }
    }
    cout << counter << std::endl;
  }
  return 0;
}
