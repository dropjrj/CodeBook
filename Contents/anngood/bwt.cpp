#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTR 1000
#define MARKER '$'
#define NUM_ALPHA 26

int comp(const void *s, const void *t) {
    return strcmp(*(char**)s, *(char**) t);    /* 猔種硂柑 *(char**) ノ猭 */
}

/* the last char of s is not MARKER */
char* bwtEncode(char *s, const int n) {
    char *L;
    char **M;
    int i, j, l;
    if ((M = (char**) malloc(sizeof(char*) * n)) == NULL || \
        (L = (char*) malloc(sizeof(char) * (n + 2))) == NULL) {
        fputs("Error: out of space!\n", stderr);
        exit(1);
    }
    for (i = 0; i < n; i++) {
        if ((M[i] = (char*) malloc(sizeof(char) * (i + 2))) == NULL) {   /* 惠玂秨繷夹癘才ê场だ才﹃硂妓羆竊丁 */
            fputs("Error: out of space!\n", stderr);
            exit(1);       
        }
        for (j = 0; j < i + 1; j++)
            M[i][j] = s[n - 1 - i + j];   /* 硂ń才﹃⊿Τ纗 MARKER */
        M[i][i + 1] = '\0';
    }
    qsort(M, n, sizeof(M[0]), comp);   /*癸臂锣才﹃逼 */
    for (i = 0, L[0] = s[n - 1]; i < n; i++) {
        if ((l = strlen(M[i])) < n)
            L[i + 1] = s[n - 1 - l];
        else
            L[i + 1] = MARKER;
    }
    L[n + 1] = '\0';
    for (i = 0; i < n; i++)
        free(M[i]);
    free(M);
    return L;
}

char* bwtDecode(char *L, const int n) {
    int i;
    int *a, *b;
    char *r;   /* original string. */
    int pos;
    if ((a = (int*) calloc(NUM_ALPHA + 1, sizeof(int))) == NULL || \
        (b = (int*) calloc(n, sizeof(int))) == NULL || \
        (r = (char*) malloc(sizeof(char) * (n + 1))) == NULL) {
        fputs("Error: out of space!\n", stderr);
        exit(1);        
    }
    for (i = 0; i < n; i++) {  /* Lい–销才计 */
        if (L[i] == MARKER) 
            a[0]++;
        else
            a[L[i] - 'a' + 1]++;
    }
    for (i = 1; i < NUM_ALPHA + 1; i++) {   /* Fい逼–销才玡ㄤ才计 */
        a[i] += a[i - 1];
    }
    for (i = 0; i < n; i++) {    /* Lい–才铬锣Fい竚 */
        if (L[i] == MARKER)
            b[i] = 0;
        else
            b[i] = a[L[i] - 'a']++;
    }
    for (i = 0, pos = 0; i < n; i++) {
        r[n - 1 - i] = L[pos];
        pos = b[pos];
    }
    r[n] = '\0';
    free(a);
    free(b);
    return r;
}

int main(void) {
    char s[MAXSTR];
    char *L;
    int n;
    char *r;
    printf("input str: ");
    fgets(s, MAXSTR - 1, stdin);
    n = strlen(s);
    if (s[n - 1] == '\n')
        s[--n] = '\0';
    L = bwtEncode(s, n);
    printf("The L column: %s\n", L);
    r = bwtDecode(L, ++n);
    printf("The original str: %s\n", r);
    free(L);
    free(r);
}