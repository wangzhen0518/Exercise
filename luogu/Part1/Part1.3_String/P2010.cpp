// https://www.luogu.com.cn/problem/P2010
#include <iostream>

inline void date2date(char* s, int& year, int& month, int& day) {
  year = month = day = 0;
  for (int i = 0; i < 4; ++i)
    year = year * 10 + s[i] - '0';
  for (int i = 4; i < 6; ++i)
    month = month * 10 + s[i] - '0';
  for (int i = 6; i < 8; ++i)
    day = day * 10 + s[i] - '0';
}

inline bool is_leap(int year) {
  if (year % 400 == 0)
    return true;
  else if (year % 100 == 0)
    return false;
  else if (year % 4 == 0)
    return true;
  else
    return false;
}

int main() {
  int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year1, month1, day1;
  int year2, month2, day2;
  char date[9];
  scanf("%s", date);
  getchar();
  date2date(date, year1, month1, day1);
  scanf("%s", date);
  date2date(date, year2, month2, day2);

  int count = 0;
  for (int y = year1; y <= year2; ++y) {
    if (is_leap(y))
      days[2] = 29;
    else
      days[2] = 28;
    int y_temp = y;
    int m = 0, d = 0;
    for (int i = 0; i < 2; ++i) {
      m = m * 10 + y_temp % 10;
      y_temp /= 10;
    }
    for (int i = 0; i < 2; ++i) {
      d = d * 10 + y_temp % 10;
      y_temp /= 10;
    }
    if (m <= 12 && d <= days[m]) {
      if (y == year1 && ((m > month1) || (m == month1 && d >= day1)))
        ++count;
      else if (y == year2 && ((m < month2) || (m == month2 && d <= day2)))
        ++count;
      else
        ++count;
    }
  }
  printf("%d\n", count);
  return 0;
}