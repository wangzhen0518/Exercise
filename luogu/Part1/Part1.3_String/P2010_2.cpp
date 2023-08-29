#include <cstring>
#include <iostream>
#include <string>

struct Date {
  int year;
  int month;
  int day;
};

const int num_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_run(int year) {
  if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    return true;
  else
    return false;
}

Date split_date(std::string const& s) {
  Date d;
  int record = atoi(s.c_str());
  d.year = record / 10000;
  d.month = (record - d.year * 10000) / 100;
  d.day = record % 100;
  return d;
}

std::string concat_date(Date const& d) {
  char new_date[9];
  snprintf(new_date, 9, "%04d%02d%02d", d.year, d.month, d.day);
  return std::string(new_date);
}

Date next_date(Date const& d) {
  Date next_day = d;
  if (d.month == 2 && d.day == 28) {
    if (is_run(d.year))
      next_day.day = 29;
    else {
      next_day.month = 3;
      next_day.day = 1;
    }
  } else if (d.month == 2 && d.day == 29) {
    next_day.month = 3;
    next_day.day = 1;
  } else if (d.month == 12 && d.day == 31) {
    next_day.year++;
    next_day.month = next_day.day = 1;
  } else if (d.day == num_day[d.month - 1]) {
    next_day.month++;
    next_day.day = 1;
  } else
    next_day.day++;
  return next_day;
}

bool earlier(Date const& d1, Date const& d2) {
  if (d2.year > d1.year)
    return true;
  else if (d2.year == d1.year && d2.month > d1.month)
    return true;
  else if (d2.year == d1.year && d2.month == d1.month && d2.day >= d1.day)
    return true;
  else
    return false;
}

bool is_palindrome(Date const& d) {
  std::string s = concat_date(d);
  int len = s.length();
  int i = 0;
  for (; i < len / 2; ++i)
    if (s[i] != s[len - i - 1])
      break;
  if (i == len / 2)
    return true;
  else
    return false;
}

int main() {
  std::string start, end;
  getline(std::cin, start);
  getline(std::cin, end);
  Date start_day = split_date(start);
  Date end_day = split_date(end);

  int cnt = 0;
  Date next_day = start_day;
  while (earlier(next_day, end_day)) {
    if (is_palindrome(next_day))
      cnt++;
    next_day = next_date(next_day);
  }
  printf("%d", cnt);
  return 0;
}