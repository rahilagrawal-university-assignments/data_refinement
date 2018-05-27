#include "dict.h"
#include <stdio.h>
#include <stdlib.h>

void newdict(Dict *dp) {
    *dp = malloc(sizeof(TNode));
    if (*dp == NULL) {
        return; 
    }
    for (int i = 0; i < VECSIZE; i++) {
        ((*dp)->cvec)[i] = NULL;
    }
    (*dp)->eow = FALSE;
}

// void addword (const Dict r, const word w) {
//     Dict loop = r;
//     int i;
//     for (i = 0; w[i] != '\0'; i++) {
//         if ((loop->cvec)[w[i]-'a'] == NULL)
//             newdict(&((loop->cvec)[w[i] - 'a']));
//         loop = (loop->cvec)[w[i] - 'a'];
//     }
//     loop->eow = TRUE;
// }

void addr (Dict r, const word w, int i) {
    if (w[i] == '\0') {
        r->eow = TRUE;
        return;
    } else {
        if ((r->cvec)[w[i]-'a'] == NULL) newdict(&((r->cvec)[w[i] - 'a']));
        r = (r->cvec)[w[i]-'a'];
        i=i+1;
        addr(r, w, i);
    }
}

void addword(const Dict r, const word w) {
    int i = 0;
    addr(r, w, i);
}


bool checkr(Dict r, const word w, int i) {
    if (r == NULL) return FALSE;
    if (w[i] == '\0') {
        if (r->eow == TRUE){
             return TRUE;
        } 
        return FALSE;
    } else {
        r = (r->cvec)[w[i]-'a'];
        i=i+1;
        return checkr(r, w, i);
    }
}

bool checkword (const Dict r, const word w) {
    int i = 0;
    return checkr(r, w, i);
}



void delr(Dict r, const word w, int i) {
    if (r == NULL) return;
    if (w[i] == '\0') {
        r->eow = FALSE;
        return;
    } else {
        r = (r->cvec)[w[i]-'a'];
        i=i+1;
        delr(r, w, i);
    }
}

void delword (const Dict r, const word w) {
    int i = 0;
    delr(r, w, i);
}


void barf(char *s) {
    fprintf(stderr, "%s\n", s);
}    

void printDictR(const Dict r, char str[], int level)
{
    // If node is leaf node, it indiicates end
    // of string, so a null charcter is added
    // and string is displayed
    if (r->eow == TRUE) 
    {
        str[level] = '\0';
        printf("%s\n", str);
    }
 
    int i;
    for (i = 0; i < VECSIZE; i++) 
    {
        if (r->cvec[i] != NULL) 
        {
            str[level] = i + 'a';
            printDictR(r->cvec[i], str, level + 1);
        }
    }
}

void printDict(const Dict r) {
    char str[100];
    int level = 0;
    printDictR(r, str, level);
}

 
