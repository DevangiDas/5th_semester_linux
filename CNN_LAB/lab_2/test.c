#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(void)
{
time_t t;
time ( &t );
printf("\nThis program has been written at (date and time): %s",ctime(&t));
return 0;
}
