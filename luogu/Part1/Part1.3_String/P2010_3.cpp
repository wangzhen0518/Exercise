#include <iostream>
#include <string>

int get_year(int month, int day) {
  int year =
      (day % 10) * 1000 + (day / 10) * 100 + (month % 10) * 10 + month / 10;
  return year;
}

// 枚举月份和日期
int main() {
  int num_days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int start, end;
  scanf("%d%d", &start, &end);

  // 由于 0229 得到的年份 9220 是闰年，所以无需判断是否是0229是否在闰年出现
  int cnt = 0;
  for (int month = 1; month <= 12; ++month)
    for (int day = 1; day <= num_days[month - 1]; ++day) {
      int year = get_year(month, day);
      int sum = year * 10000 + month * 100 + day;
      if (sum >= start && sum <= end)
        cnt++;
    }
  printf("%d\n", cnt);
  return 0;
}