// List of functions
#include "functions.c"

// Supplemental functions
void menu(int *opt);
char *strLower(char *str);
int validStudnum(char *id);
int availStudnum(Nodeptr temp, char *id);
void dealloc(Nodeptr *hptr);

// Required functions
void addStud(Nodeptr *hptr, int *entriesPtr);
void showRec(Nodeptr start);
void addAbs(Nodeptr temp, int entries);
void delStud(Nodeptr *hptr,  int *entries);

// File handling functions
void saveData(FILE * src, Nodeptr temp, int entries);
void loadData(FILE * src, Nodeptr *hptr, int *entries);