#define NKEYS (sizeof keytab / sizeof(struct key))

struct key {
  char *word;
  int count;
};

extern struct key keytab[32];

