#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

#define N 255
#define MAX_WORDS 100

typedef struct counter {
  char* s;
  int count;
} counter;

static int cmpcounter(const void* c1, const void* c2) {
  return ((struct counter*)c1)->count < ((struct counter*)c2)->count;
}

static int cmpstrings(const void* c1, const void* c2) {
  return strcmp(((struct counter*)c1)->s, ((struct counter*)c2)->s);
}

int main() {
  char* words[MAX_WORDS];

  char buf[N];

  size_t count = 0;
  for (; count < MAX_WORDS; ++count) {
    if (fgets(buf, N, stdin)) {
      size_t len = strlen(buf);

      words[count] = (char*)calloc(sizeof(char), len);

      // remove trailing newline
      if (len)
        buf[len - 1] = '\0';
      else
        // skipping empty lines
        continue;

      strncpy(words[count], buf, len - 1);

    } else {
      break;
    }
  }

  for (size_t i = 0; i < count; ++i) {
    printf("%lu. slovo: %s\n", i, words[i]);
  }

  struct counter counters[MAX_WORDS];

  size_t used_counters = 0;

  for (size_t i = 0; i < count; ++i) {
    int found = FALSE;

    for (size_t j = 0; j < used_counters; ++j) {
      if (!strcmp(words[i], counters[j].s)) {
        counters[j].count++;
        found = TRUE;
      }
    }

    if (!found) {
      counters[used_counters].s = words[i];
      counters[used_counters].count = 1;
      used_counters++;
    }
  }

  printf("\npodle poctu:\n");
  qsort(counters, used_counters, sizeof(struct counter), cmpcounter);

  for (size_t i = 0; i < used_counters; ++i) {
    printf("%lu counter, %s: %d\n", i, counters[i].s, counters[i].count);
  }


  printf("\nabecedne:\n");
  qsort(counters, used_counters, sizeof(struct counter), cmpstrings);

  for (size_t i = 0; i < used_counters; ++i) {
    printf("%lu counter, %s: %d\n", i, counters[i].s, counters[i].count);
  }
}
