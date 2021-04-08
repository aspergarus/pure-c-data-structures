typedef struct ArrayList {
    int* data;
    int len;
    int cur;
    int step;
} ArrayList;

ArrayList* ArrayList_new(int size, int pos);
void ArrayList_print(ArrayList * arr);
void ArrayList_insert(ArrayList * arr, int newElement);
void ArrayList_insertAll(ArrayList * arr, int num, ...);
int ArrayList_get(ArrayList * arr, int pos);