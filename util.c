#include <stdio.h>

#define voidp void *

/* ========================================================================
 * Semi-safe malloc -- never returns NULL.
 */
voidp xmalloc (size)
    unsigned size;
{
    voidp cp;

    if (size==0) size=1;
    cp = (voidp)malloc (size);
    if (cp == NULL) fprintf(stderr, "out of memory");
    return cp;
}

voidp xrealloc (old, size)
    voidp old;
    unsigned size;
{
    voidp cp = (voidp)realloc (old, size);

    if (cp == NULL) fprintf(stderr, "out of memory");
    return cp;
}
