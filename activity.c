
#include <stdio.h>

void activitySelection(int start[], int finish[], int n)
{
    int i, count = 1;

    printf("Selected Activities:\n");
    printf("Activity %d\n", 1);

    int last = 0;

    for (i = 1; i < n; i++)
    {
        if (start[i] >= finish[last])
        {
            printf("Activity %d\n", i + 1);
            last = i;
            count++;
        }
    }

    printf("Maximum activities = %d\n", count);
}

int main()
{
    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter start times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &start[i]);

    printf("Enter finish times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &finish[i]);

    // Sort activities by finish time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (finish[j] > finish[j + 1])
            {
                int temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }

    activitySelection(start, finish, n);

    return 0;
}
