#include <iostream>

int main() {
  const int per = 300;
  int temp = 0;
  int rest = 0;
  int plan[12];
  for (int i = 0; i < 12; ++i) scanf("%d", plan + i);
  for (int i = 0; i < 12; ++i) {
    rest += per;
    rest -= plan[i];
    if (rest < 0) {
      printf("-%d\n", i + 1);
      break;
    }
    temp += rest / 100 * 100;
    rest -= rest / 100 * 100;
  }
  if (rest >= 0) {
    rest += temp * 1.2;
    printf("%d\n", rest);
  }
  return 0;
}