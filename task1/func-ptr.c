#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int arrival_time;
    int priority;
} Process;

typedef int (*Comparer)(const void *a, const void *b);

/* Sort by descending priority, then ascending arrival time. */
int my_comparer(const void *this, const void *that)
{
    const Process *left = (const Process *)this;
    const Process *right = (const Process *)that;

    if (left->priority != right->priority) {
        return right->priority - left->priority;
    }
    return left->arrival_time - right->arrival_time;
}

int main(int argc, char *argv[])
{
    FILE *input;
    Process *processes;
    size_t count = 0;
    size_t capacity = 8;
    char line[256];
    Comparer process_comparer = &my_comparer;

    if (argc != 2) {
        fprintf(stderr, "Usage: ./qsort <input-file-path>\n");
        return EXIT_FAILURE;
    }

    input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    processes = malloc(capacity * sizeof(*processes));
    if (processes == NULL) {
        fclose(input);
        return EXIT_FAILURE;
    }

    (void)fgets(line, sizeof(line), input); /* discard CSV header */
    while (fgets(line, sizeof(line), input) != NULL) {
        Process process;
        if (sscanf(line, " %d , %d , %d",
                   &process.pid, &process.arrival_time, &process.priority) == 3) {
            if (count == capacity) {
                Process *grown;
                capacity *= 2;
                grown = realloc(processes, capacity * sizeof(*processes));
                if (grown == NULL) {
                    free(processes);
                    fclose(input);
                    return EXIT_FAILURE;
                }
                processes = grown;
            }
            processes[count++] = process;
        }
    }

    qsort(processes, count, sizeof(*processes), process_comparer);
    for (size_t i = 0; i < count; ++i) {
        printf("%d (%d, %d)\n", processes[i].pid,
               processes[i].priority, processes[i].arrival_time);
    }

    free(processes);
    fclose(input);
    return EXIT_SUCCESS;
}
