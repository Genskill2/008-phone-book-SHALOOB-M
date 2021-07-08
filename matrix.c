#include <stdio.h>
#include <stdlib.h>


int **create_matrix(int m, int n, int);
void print_matrix(int **, int m, int n);



int **create_matrix(int m, int n, int init) {
  int **ret;
  ret = malloc(sizeof(int *) *m); /* ret is int ** */
  
  /* ret[0]=malloc(sizeof(int) * n); /\* ret[0] is the same as *(ret+0) is the same as *ret. It is int * *\/ */
  /* ret[1]=malloc(sizeof(int) * n); /\* ret[0] is the same as *(ret+0) is the same as *ret. It is int * *\/ */
  /* ret[2]=malloc(sizeof(int) * n); /\* ret[0] is the same as *(ret+0) is the same as *ret. It is int * *\/ */
  /* . */
  /* . */
  /* . */
  /* ret[m]=malloc(sizeof(int) * n); /\* ret[0] is the same as *(ret+0) is the same as *ret. It is int * *\/ */
  for (int i=0; i<m; i++) {
    ret[i] = malloc(sizeof(int) * n);
    for (int j=0; j<n; j++) {
      ret[i][j] = init;
    }
  }
  return ret;
}

void print_matrix(int **matrix, int m, int n) {
  for(int i=0; i<m; i++) {
    for (int j=0; j<n; j++)
      printf("%3i ", matrix[i][j]);
    printf("\n");
  }
}

int **add(int **m0, int **m1,  int m, int n) {
  int **ret = create_matrix(m, n, 0);
  for (int i=0; i<m; i++) 
    for (int j=0; j<n; j++) 
      ret[i][j] = m0[i][j] + m1[i][j];
  return ret;
}


int main(void) {
  int **m1 = create_matrix(4, 4, 2);
  int **m2 = create_matrix(4, 4, 3);
  int **s = add(m1, m2, 4, 4);
  print_matrix(s, 4, 4);
}

