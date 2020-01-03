#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

struct word_tree {
  char *word;
  int count;
  struct word_tree *left;
  struct word_tree *right;
};

struct match {
  char *pattern;
  struct word_tree *word_root;
  int count;
  struct match *left;
  struct match *right;
};

int get_word(char *word, int lim);
char *substring(char *, int, int);
void matches_print(struct match *p);

int main(int argc, char *argv[]) {
  int matching_letters;
  char word[MAX_LENGTH];
  struct match *matches;
  struct match *add_match(struct match *, char *, char *);
  matching_letters = argc > 1 ? atoi(argv[1]) : 6;

  matches = NULL;
  while (get_word(word, MAX_LENGTH) != EOF) {
    matches = add_match(matches, substring(word, 0, matching_letters - 1), word);
  }

  matches_print(matches);

  return 0;
}

void tree_print(struct word_tree *p) {
  if (p != NULL) {
    tree_print(p->left);
    printf("\t%4d %s\n", p->count, p->word);
    tree_print(p->right);
  }
}

void matches_print(struct match *p) {
  if (p != NULL) {
    matches_print(p->left);
    printf("%4d %s\n", p->count, p->pattern);
    tree_print(p->word_root);
    matches_print(p->right);
  }
}

struct word_tree *word_alloc(void) {
  return (struct word_tree *)malloc(sizeof(struct word_tree));
}

struct word_tree *add_word(struct word_tree *p, char *word) {
  int cond;
  struct word_tree *word_alloc(void);
  char *duplicate_string(char *s);
  if (p == NULL) {
    p = word_alloc();
    p->word = duplicate_string(word);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(word, p->word)) == 0) {
    p->count++;
  } else if (cond < 0) {
    p->left = add_word(p->left, word);
  } else {
    p->right = add_word(p->right, word);
  }
  return p;
}

struct match *match_alloc(void) {
  return (struct match *)malloc(sizeof(struct match));
}

struct match *add_match(struct match *p, char *pattern, char *word) {
  int i;
  int cond;
  struct match *match_alloc(void);
  struct word_tree *add_word(struct word_tree *, char *);
  if (p == NULL) {
    p = match_alloc();
    p->count = 1;
    p->pattern = pattern;
    p->right = p->left = NULL;
    p->word_root = add_word(NULL, word);
  } else if ((cond = strcmp(pattern, p->pattern)) == 0) {
    p->count++;
    p->word_root = add_word(p->word_root, word);
  } else if (cond < 0) {
    p->left = add_match(p->left, pattern, word);
  } else {
    p->right = add_match(p->right, pattern, word);
  }
  return p;
}

