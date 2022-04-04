// https://www.luogu.com.sh/problem/P1051
#include <iostream>

struct student {
  char name[21];
  int finalScore, classScore;
  bool leader, west;
  int paper;
  int sh;
};

inline int count(const student& s) {
  int sh = 0;
  if (s.finalScore > 80 && s.paper >= 1) sh += 8000;
  if (s.finalScore > 85 && s.classScore > 80) sh += 4000;
  if (s.finalScore > 90) sh += 2000;
  if (s.finalScore > 85 && s.west) sh += 1000;
  if (s.classScore > 80 && s.leader) sh += 850;
  return sh;
}

int main() {
  int N;
  scanf("%d", &N);
  student* st = new student[N];
  char leader, west;
  int sum = 0, an = 0, max = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%s%d%d %c %c%d", st[i].name, &st[i].finalScore, &st[i].classScore,
          &leader, &west, &st[i].paper);
    st[i].leader = leader == 'Y' ? true : false;
    st[i].west = west == 'Y' ? true : false;
    st[i].sh = count(st[i]);
    sum += st[i].sh;
    if (st[i].sh > max) {
      max = st[i].sh;
      an = i;
    }
  }
  printf("%s\n%d\n%d", st[an].name, st[an].sh, sum);
  delete[] st;
  return 0;
}