#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

typedef struct {
    int *queue;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

CircularQueue* createQueue(int capacity) {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->queue = (int*)malloc(capacity * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

int isEmpty(CircularQueue* q) {
    return q->size == 0;
}

int isFull(CircularQueue* q) {
    return q->size == q->capacity;
}

void enqueue(CircularQueue* q, int pid) {
    if (isFull(q)) return;
    
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->capacity;
    }
    q->queue[q->rear] = pid;
    q->size++;
}

int dequeue(CircularQueue* q) {
    if (isEmpty(q)) return -1;
    
    int pid = q->queue[q->front];
    if (q->size == 1) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->capacity;
    }
    q->size--;
    return pid;
}

void sortByArrivalTime(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void fcfsScheduling(Process processes[], int n) {
    sortByArrivalTime(processes, n);
    
    CircularQueue* readyQueue = createQueue(n);
    int current_time = 0;
    int completed = 0;
    int i = 0;
    
    while (completed < n) {
        while (i < n && processes[i].arrival_time <= current_time) {
            enqueue(readyQueue, i);
            i++;
        }
        
        if (!isEmpty(readyQueue)) {
            int current_process = dequeue(readyQueue);
            
            processes[current_process].start_time = current_time;
            processes[current_process].completion_time = current_time + processes[current_process].burst_time;
            processes[current_process].turnaround_time = processes[current_process].completion_time - processes[current_process].arrival_time;
            processes[current_process].waiting_time = processes[current_process].turnaround_time - processes[current_process].burst_time;
            
            current_time = processes[current_process].completion_time;
            completed++;
        } else {
            if (i < n) {
                current_time = processes[i].arrival_time;
            }
        }
    }
    
    free(readyQueue->queue);
    free(readyQueue);
}

void printResults(Process processes[], int n) {
    printf("PID\tAT\tBT\tST\tCT\tWT\tTT\n");
    
    float total_wt = 0, total_tt = 0;
    
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].start_time,
               processes[i].completion_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
        
        total_wt += processes[i].waiting_time;
        total_tt += processes[i].turnaround_time;
    }
    
    printf("\nAverage WT: %.2f\n", total_wt / n);
    printf("Average TT: %.2f\n", total_tt / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    Process *processes = (Process*)malloc(n * sizeof(Process));
    
    for (int i = 0; i < n; i++) {
        printf("Enter details for Process P%d:\n", i + 1);
        processes[i].pid = i + 1;
        
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        
        printf("\n");
    }
    
    fcfsScheduling(processes, n);
    printResults(processes, n);
    
    free(processes);
    return 0;
}