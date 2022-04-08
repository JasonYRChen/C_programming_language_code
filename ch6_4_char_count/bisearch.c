#include "char_count.h"
#include <stdio.h>

struct key *bisearch(char c, struct key *low, struct key *high)
{
    if (high >= low) {
        struct key *mid = low + (high - low) / 2;
        if (mid->name == c)
            return mid;
        if (mid->name > c)
            return bisearch(c, low, mid - 1);
        return bisearch(c, mid + 1, high);
    }
    return NULL;
}

