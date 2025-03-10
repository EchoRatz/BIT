#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct {  
    int start;  
    int end;  
} Task;  
  
int compare(const void *a, const void *b) {  
    Task *task1 = (Task *)a;  
    Task *task2 = (Task *)b;  
    return task1->end - task2->end;  
}  
  
int main() {  
    int n;  
    scanf("%d", &n);  
  
    Task tasks[n];  
    for (int i = 0; i < n; i++) {  
        scanf("%d %d", &tasks[i].start, &tasks[i].end);  
    }  
  
    qsort(tasks, n, sizeof(Task), compare);  
  
    int count = 0;  
    int last_end_time = 0;  
  
    for (int i = 0; i < n; i++) {  
        if (tasks[i].start >= last_end_time) {  
            count++;  
            last_end_time = tasks[i].end;  
        }  
    }  
  
    printf("%d\n", count);  
    return 0;  
}