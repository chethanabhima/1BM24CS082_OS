#include <stdio.h>

struct Process {
    int id;
    int at;
    int bt;
    int priority;
    int ct;
    int wt;
    int tat;
    int rt;   // for preemptive
    int comp;
};

int main() {
    int n, choice;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;

        printf("\nProcess %d\n", p[i].id);

        printf("Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Priority: ");
        scanf("%d", &p[i].priority);
    }

    printf("\nChoose Scheduling Type:");
    printf("\n1. Non-Preemptive Priority");
    printf("\n2. Preemptive Priority");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    // NON-PREEMPTIVE
    if (choice == 1) {
        int cur_time = 0, completed = 0;

        // initialize
        for (int i = 0; i < n; i++) {
            p[i].comp = 0;
        }

        while (completed < n) {
            int idx = -1;
            int high_priority = 9999;

            for (int i = 0; i < n; i++) {
                if (p[i].at <= cur_time && p[i].comp == 0) {
                    if (p[i].priority < high_priority) {
                        high_priority = p[i].priority;
                        idx = i;
                    }
                }
            }

            if (idx == -1) {
                cur_time++;
            } else {
                p[idx].ct = cur_time + p[idx].bt;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;

                cur_time = p[idx].ct;
                p[idx].comp = 1;
                completed++;
            }
        }
    }

    // PREEMPTIVE
    else if (choice == 2) {
        int cur_time = 0, completed = 0;


        for (int i = 0; i < n; i++) {
            p[i].rt = p[i].bt;
        }

        while (completed < n) {
            int idx = -1;
            int high_priority = 9999;

            for (int i = 0; i < n; i++) {
                if (p[i].at <= cur_time && p[i].rt > 0) {
                    if (p[i].priority < high_priority) {
                        high_priority = p[i].priority;
                        idx = i;
                    }
                }
            }

            if (idx == -1) {
                cur_time++;
            } else {
                p[idx].rt--;
                cur_time++;

                if (p[idx].rt == 0) {
                    p[idx].ct = cur_time;
                    p[idx].tat = p[idx].ct - p[idx].at;
                    p[idx].wt = p[idx].tat - p[idx].bt;
                    completed++;
                }
            }
        }
    }

    else {
        printf("Invalid choice\n");
        return 0;
    }

    float total_WT = 0, total_TAT = 0;

    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        total_WT += p[i].wt;
        total_TAT += p[i].tat;

        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt, p[i].priority,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f", total_WT / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_TAT / n);

    return 0;
}
