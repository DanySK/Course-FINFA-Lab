#include <glib.h>
#include <stdio.h>

void prt(GArray* a) {
   printf("[ ");
   int i;
   for (i = 0; i < a->len; i++) {
      printf("%d ", g_array_index(a, int, i));
   }
   printf("]\n");
}

int compare_ints(gpointer a, gpointer b) {
   return *(int *) a - *(int *) b;
}

int main(int argc, char** argv) {
   GArray* a = g_array_new(FALSE, FALSE, sizeof(int));
   printf("Array is empty, so appending a value: ");
   int z = 0;
   g_array_append_val(a, z);
   prt(a);
   printf("Appending more values: ");
   int x[2] = {4,5};
   g_array_append_vals(a, &x, 2);
   prt(a);
   printf("Now to prepend some values: ");
   int y[2] = {2,3};
   g_array_prepend_vals(a, &y, 2);
   prt(a);
   printf("And one more prepend: ");
   g_array_prepend_val(a, z);
   prt(a);
   printf("We can insert data in between: ");
   g_array_insert_vals(a, 2, x, 2);
   prt(a);
   printf("Removing those two items: ");
   g_array_remove_range(a, 2, 2);
   prt(a);
   printf("Removing the last one: ");
   g_array_remove_index(a, a->len -1);
   prt(a);
   printf("Sorting: ");
   g_array_sort(a, (GCompareFunc)compare_ints);
   prt(a);
   g_array_free(a, FALSE);
   return 0;
}
