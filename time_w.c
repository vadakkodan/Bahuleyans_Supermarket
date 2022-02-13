#include <assert.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    char tim[64];
    assert(strftime(s, sizeof(s), "Date:  %d-%b-%G", tm));
    assert(strftime(tim, sizeof(tim),"Time:  %I:%M %p", tm));

    printf("%s\n", s);
    printf("%s\n", tim);
    return 0;
}
