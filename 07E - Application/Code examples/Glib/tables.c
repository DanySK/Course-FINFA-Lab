#include <glib.h>
#include <stdio.h>

void print_kv(gpointer key, gpointer value, gpointer user_data) {
  printf("[%s -> %s] ", (char *)key, (char *)value);
}

void printMap(GHashTable *map) {
  printf("Map: { ");
  g_hash_table_foreach(map, (GHFunc)print_kv, NULL);
  printf("}\n");
}

int main(int argc, char** argv) {
  GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
  g_hash_table_insert(hash, "Queen", "Freddie Mercury");
  g_hash_table_insert(hash, "Korn", "Jonathan Davis");
  g_hash_table_insert(hash, "Diablo Swing Orchestra", "Annlouice Loegdlund");
  g_hash_table_insert(hash, "Nightwish", "Tarja Turunen");
  printMap(hash);
  printf("The lead vocal of Queen is (was :() %s\n", (char *)g_hash_table_lookup(hash, "Queen"));
  printf("The lead vocal of Evanescence is %s\n", (char *)g_hash_table_lookup(hash, "Evanescence"));
  gboolean found = g_hash_table_remove(hash, "Nightwish");
  printf("The key 'Nightwish' was %sfound and removed\n", found ? "" : "NOT ");
  found = g_hash_table_remove(hash, "Evanescence");
  printf("The key 'Evanescence' was %sfound and removed\n", found ? "" : "NOT ");
  printMap(hash);
  g_hash_table_destroy(hash);
  return 0;
}

