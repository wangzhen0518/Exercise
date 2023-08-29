// https://www.luogu.com.cn/problem/P1308
#include <iostream>
#include <vector>

inline bool pattern_match(std::string& article, std::string& word, int p) {
  int i = 0;
  while (article[p] && word[i] == article[p])
    ++p, ++i;
  if (!word[i] && !article[p])
    return true;
  else
    return false;
}

int main() {
  using std::cin;
  using std::string;
  using std::vector;

  string word;
  string article;
  vector<int> p;
  getline(cin, word);
  getline(cin, article);
  int len1 = word.length(), len2 = article.length();
  
  // 将 word 转为小写
  int i = 0;
  while (i < len1) {
    word[i] = tolower(word[i]);
    ++i;
  }
  // 将 article 全部用 '\0' 切分，并转为小写，p中记录了所有单词的起始位置
  i = 0;
  while (article[i] == ' ') {
    article[i] = '\0';
    ++i;
  }
  p.emplace_back(i);
  while (i < len2) {
    if (article[i] == ' ') {
      while (article[i] == ' ') {
        article[i] = '\0';
        ++i;
      }
      p.emplace_back(i);
    }
    article[i] = tolower(article[i]);
    ++i;
  }

  int position = -1;
  int count = 0;
  for (i = 0; i < p.size(); ++i) {
    if (pattern_match(article, word, p[i])) {
      ++count;
      if (position == -1)
        position = p[i];
    }
  }

  if (count)
    printf("%d %d\n", count, position);
  else
    printf("-1\n");
  return 0;
}