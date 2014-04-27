#include <stdio.h>

void display_intarr(int *arr, int len)
{
    int numi;

    for (numi=0; numi<len; numi++)
    {
        printf("%d%c", arr[numi], " \n"[numi + 1 < len ? 0 : 1]);
    }
}

void q_sort(int *arr, int len)
{
    int flag;
    int l, r;

    if (len < 2)
        return;

    l = 0;
    r = len - 1;
    flag = arr[r];

    while (l < r)
    {
        while (l < r)
        {
            if (arr[l] > flag)
            {
                arr[r] = arr[l];
                break;
            }

            l++;
        }

        while (l < r)
        {
            if (arr[r] < flag)
            {
                arr[l] = arr[r];
                break;
            }

            r--;
        }
    }

    arr[l] = flag;

    q_sort(arr, l);
    q_sort(arr + l + 1, len - l - 1);
}

int main(int argc, char *argv[])
{
    int n, range;
    int num_arr[10];
    int casei;
    int numi;

    srand((unsigned)time(NULL));

    if (argc < 3)
    {
        printf("please input number of case and range:");
        scanf("%d%d", &n, &range);
    }
    else
    {
        n = atoi(argv[1]);
        range = atoi(argv[2]);
    }

    for (casei=1; casei<=n; casei++)
    {
        printf("case %d:\n", casei);

        for (numi=0; numi<10; numi++)
        {
            num_arr[numi] = rand() % range;
        }

        printf("%-10s", "original:");
        display_intarr(num_arr, 10);

        q_sort(num_arr, 10);

        printf("%-10s", "sorted:");
        display_intarr(num_arr, 10);

        printf("\n");
    }

}
