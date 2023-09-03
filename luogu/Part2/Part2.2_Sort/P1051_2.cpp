#include <iostream>

struct Student {
  std::string name;
  int test_score;
  int class_score;
  bool is_staff;
  bool is_west;
  int paper_num;
  int scholarship;
};

int count(Student& s) {
  s.scholarship = 0;
  if (s.test_score > 80 && s.paper_num >= 1)
    s.scholarship += 8000;
  if (s.test_score > 85 && s.class_score > 80)
    s.scholarship += 4000;
  if (s.test_score > 90)
    s.scholarship += 2000;
  if (s.test_score > 85 && s.is_west)
    s.scholarship += 1000;
  if (s.class_score > 80 && s.is_staff)
    s.scholarship += 850;
  return s.scholarship;
}

int main() {
  int N;
  scanf("%d", &N);
  Student* a = new Student[N];
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i].name >> a[i].test_score >> a[i].class_score;
    getchar();
    char c = getchar();
    a[i].is_staff = (c == 'Y');
    getchar();
    c = getchar();
    a[i].is_west = (c == 'Y');
    std::cin >> a[i].paper_num;
  }
  int sum = 0;
  int max_idx = 0, max_cnt = 0;
  for (int i = 0; i < N; ++i) {
    int cnt = count(a[i]);
    sum += cnt;
    if (cnt > max_cnt) {
      max_idx = i;
      max_cnt = cnt;
    }
  }
  printf("%s\n%d\n%d", a[max_idx].name.c_str(), a[max_idx].scholarship, sum);
  delete[] a;
  return 0;
}