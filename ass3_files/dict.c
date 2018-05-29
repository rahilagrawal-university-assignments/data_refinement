#include "dict.h"
#include <stdio.h>
#include <stdlib.h>

void newdict(Dict *dp) {
    *dp = malloc(sizeof(TNode));
    if (*dp == NULL) {
        return;
    }
    int i=0;
    for (i = 0; i < VECSIZE; i++) {
        ((*dp)->cvec)[i] = NULL;
    }
    (*dp)->eow = FALSE;
}

void addR (Dict r, const word w, int i) {
    if (w[i] == '\0') {
        r->eow = TRUE;
        return;
    } else {
        if ((r->cvec)[w[i] - 'a'] == NULL) newdict(&((r->cvec)[w[i] - 'a']));
        r = (r->cvec)[w[i] - 'a'];
        i = i + 1;
        addR(r, w, i);
    }
}

bool checkR(Dict r, const word w, int i) {
    if (r == NULL) return FALSE;
    if (w[i] == '\0') {
        if (r->eow == TRUE) {
            return TRUE;
        }
        return FALSE;
    } else {
        r = (r->cvec)[w[i] - 'a'];
        i = i + 1;
        return checkR(r, w, i);
    }
}

void delR(Dict r, const word w, int i) {
    if (r == NULL) return;
    if (w[i] == '\0') {
        r->eow = FALSE;
        return;
    } else {
        r = (r->cvec)[w[i] - 'a'];
        i = i + 1;
        delR(r, w, i);
    }
}

void barf(char *s) {
    fprintf(stderr, "%s\n", s);
}

void addword(const Dict r, const word w) {
    int i = 0;
    addR(r, w, i);
}

bool checkword (const Dict r, const word w) {
    int i = 0;
    return checkR(r, w, i);
}

void delword (const Dict r, const word w) {
    int i = 0;
    delR(r, w, i);
}