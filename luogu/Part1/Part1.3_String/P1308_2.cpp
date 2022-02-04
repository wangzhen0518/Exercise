// https://www.luogu.com.cn/problem/P1308
#include <iostream>

int main() {
  char word[13];
  char article[1000003];
  word[0] = ' ';
  article[0] = ' ';
  scanf("%s", word + 1);
  getchar();
  std::cin.getline(article + 1, 1000000);

  int len1 = 0;
  while (word[len1]) {
    word[len1] = tolower(word[len1]);
    ++len1;
  }
  word[len1++] = ' ';
  int len2 = 0;
  while (article[len2]) {
    article[len2] = tolower(article[len2]);
    ++len2;
  }
  article[len2++] = ' ';

  int position = -1;
  int count = 0;
  for (int j = 0; j < len2; ++j) {
    int i = 0, k = j;
    while (k < len2 && word[i] == article[k]) {
      ++i;
      ++k;
    }
    if (i == len1) {
      ++count;
      printf("%d\n", k - len1);
      if (position == -1)
        position = k - len1;
    }
  }
  if (count)
    printf("%d %d\n", count, position);
  else
    printf("-1\n");
  return 0;
}