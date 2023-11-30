typedef struct journal{
    char name[40];
    char author[60];
    int views;
}journal;
void create(journal **arr, int*n);
void read(journal **arr, int *n);
void write(journal *arr, int n);