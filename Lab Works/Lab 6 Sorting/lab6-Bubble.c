#include <stdio.h>

void printArray(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d\t", *(arr + i));

  printf("\n\n");
}

int main()
{
  int n = 10;
  int i, j, temp;
  int array[10] = {3, 8, 7, 10, 1, 4, 2, 5, 6, 9};
  printArray(&array[0], n);
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (array[j] > array[j + 1]) /* For decreasing order use < */
      {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        printArray(&array[0], n);
      }
    }
  }
  printf("Below is the list of elements sorted in ascending order:\n");
  printArray(&array[0], n);
  return 0;
}
