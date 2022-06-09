#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define SUCCESS  0
#define MEM_ERR -1

int free_sched(char **sched, int sched_alloc_len);
char** alloc_sched(int sched_alloc_len, int num_nodes);
int test_all_scheds(char **sched, int makespan);

int main(int argc, char *argv[]) {
    double alpha = .5;
    int ss_size = 4;
    int num_nodes = 10;
    assert(0 <= alpha && alpha  <= 1);
    assert(0 < ss_size);
    assert(0 < num_nodes);

    int sched_alloc_len = 2;
    char **sched;

    int makespan;
    for(makespan = 2; ; ++makespan) {

        test_all_scheds(sched, makespan);

        if(makespan + 1 > sched_alloc_len) {
            sched_alloc_len *= 2;
            free_sched(sched, sched_alloc_len);
            if(alloc_sched(sched_alloc_len, num_nodes) == NULL) return MEM_ERR;
        }
    }

    return 0;
}

int test_all_scheds(char **sched, int makespan) {

    return SUCCESS;
}

int free_sched(char **sched, int sched_alloc_len) {
    int arr_ind;
    for(arr_ind = 0; arr_ind < sched_alloc_len; ++arr_ind) {
        free(sched[arr_ind]);
    }
    free(sched);

    return SUCCESS;
}

char** alloc_sched(int sched_alloc_len, int num_nodes) {

    char **sched = malloc(sizeof(char*) * sched_alloc_len);
    if(sched == NULL) return NULL;

    int arr_ind;
    for(arr_ind = 0; arr_ind < sched_alloc_len; ++arr_ind) {
        sched[arr_ind] = malloc(sizeof(char) * num_nodes);
        if(sched[arr_ind] == NULL) return NULL;
    }

    return sched;
}
