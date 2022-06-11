#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*     SOLVED     */

#define MAX_FLNZ 23

void solve (const char *filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
        printf("Failed to open file \'%s\'...", filename);
    else {
        char *current_line = (char*) malloc(MAX_FLNZ * sizeof(char));
        int lastLineDepth = 0;
        int largerLineDepthCounter = 0;

        while (fgets(current_line, MAX_FLNZ, fptr)) {
            if (lastLineDepth > 0 && atoi(current_line) > lastLineDepth)
                largerLineDepthCounter += 1;
            lastLineDepth = atoi(current_line);
        }

        printf("largerLineDepthCounter = %d", largerLineDepthCounter);
        free(current_line);
        fclose(fptr);
    }
}

int main (void) {
    solve("day1.txt");
    return 0;
}
