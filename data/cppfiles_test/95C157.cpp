#include <bits/stdc++.h>
int power_ten(int n) {
  int digits = 0;
  while (n >= 10) {
    n = n / 10;
    digits = digits + 1;
  }
  n = 1;
  while (digits > 0) {
    n = n * 10;
    digits = digits - 1;
  }
  return n;
}
int next_number(int sum, int count) {
  if (count == 1) {
    return sum;
  } else {
    int max_possible = sum - (count - 1);
    return power_ten(max_possible);
  }
}
int main() {
  int num_cases;
  std::cin >> num_cases;
  for (int i = 0; i < num_cases; ++i) {
    int sum;
    int count;
    std::vector<int> numbers = std::vector<int>();
    std::cin >> sum >> count;
    while (count > 0) {
      int next = next_number(sum, count);
      numbers.push_back(next);
      sum = sum - next;
      count = count - 1;
    }
    for (int x : numbers) {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}
