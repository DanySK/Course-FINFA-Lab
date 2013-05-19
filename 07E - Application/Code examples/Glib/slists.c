#include <glib.h>
#include <stdio.h>

void prt(GSList* a) {
  printf("[ ");
  GSList * iterator = a;
  for (; iterator != NULL; iterator = iterator->next) {
    printf("%s ", (char *)(iterator->data));
  }
  printf("]\n");
}

int main(int argc, char** argv) {
  GSList* list = NULL;
  printf("The list is : ");
  list = g_slist_append(list, "two");
  list = g_slist_prepend(list, "one");
  printf("Adding some strings: ");
  prt(list);
  list = g_slist_remove(list, "one");
  printf("Removing \"one\": ");
  prt(list);
  list = g_slist_append(list, "two");
  list = g_slist_append(list, "two");
  list = g_slist_append(list, "three");
  printf("Adding more data: ");
  prt(list);
  list = g_slist_remove_all(list, "two");
  printf("Removing all the \"two\"s: ");
  prt(list);
  g_slist_free(list);
  return 0;
}
