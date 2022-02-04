// https://www.luogu.com.cn/problem/P1055
#include <stdio.h>
int main(void) {
  char str[14], mod[12] = "0123456789X";
  scanf("%s", str);
  int i, j = 1, t = 0;
  for (i = 0; i < 12; i++)
    if (str[i] != '-')
      t += (str[i] - '0') * j++;

  if (mod[t % 11] == str[12])
    printf("Right\n");
  else {
    str[12] = mod[t % 11];
    printf("%s\n", str);
  }
  return 0;
}