//1. FCFS(First - Come - First - Serve)
#include <stdio.h>

void fcfs(int processes[], int n, int bt[]) {
    int wt[n], tat[n];

    // Waiting time for the first process is 0
    wt[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    // Calculate turnaround time
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    // Print results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
}

int main() {
    int processes[] = { 1, 2, 3 };
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = { 10, 5, 8 };

    fcfs(processes, n, burst_time);

    return 0;
}
