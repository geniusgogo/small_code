#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

#define DEV_NAME "/dev/GlobalChar"

int main()
{
    int fd, num;

    fd = open(DEV_NAME, O_RDWR, S_IRUSR | S_IWUSR);

    if (fd < 0)
    {
        printf("Open Device fail!\n");
        return -1;
    }

    read(fd, &num, sizeof(int));

    printf("The GlobalChar is %d\n", num);

    printf("Please input a number written to GlobalChar: ");
    scanf("%d", &num);

    write(fd, &num, sizeof(int));

    read(fd, &num, sizeof(int));
    printf("The GlobalChar is %d\n", num);

    close(fd);

    return 0;
}
