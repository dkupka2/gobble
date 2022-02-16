// An extremely useless program that allocates 2.1GB of memory,
// modifies each byte to store the character '1',
// and dumps this all out to file 'file.out'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(void) {
  FILE *fp;
  char *chunk = NULL;

  if (NULL == (chunk = malloc(INT_MAX * sizeof(char)))) {
    printf("Unable to allocate memory!\n");
    return 1;
  }

  if (NULL == (fp = fopen("file.out", "w"))) {
    printf("Unable to open file for writing!\n");
    return 1;
  }

  fprintf(fp, "Start address: %p\n", chunk);
  printf("Start address: %p\n", chunk);

  int i = 0;

  while (i < INT_MAX) {
    chunk[i] = '1';
    fprintf(fp, "%c", chunk[i]);
    i++;
  }

  fprintf(fp, "End address: %p\n", &chunk[i - 1]);
  printf("End address: %p\n", &chunk[i - 1]);

  fprintf(fp, "%lu\n", strlen(chunk));
  printf("%lu\n", strlen(chunk));

  if (fp != NULL) {
    fclose(fp);
  }

  if (chunk != NULL) {
    free(chunk);
  }

  chunk = NULL;

  return 0;
}
