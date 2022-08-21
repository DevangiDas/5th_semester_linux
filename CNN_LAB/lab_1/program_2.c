#include <stdio.h>
#include <string.h>

 struct student
{
  int roll_no;
  char name[50];
  float CGPA;
};
void func(struct student *info );
int main()
{
    struct student info;
    info.roll_no=2006017;
    strcpy(info.name, "DEVANGI DAS");
          info.CGPA = 9.27;

          func(&info);
          return 0;
}

void func(struct student *info)
{
          printf(" roll_no is: %d \n", info->roll_no);
          printf(" Name is: %s \n", info->name);
          printf(" CGPA is : %f\n", info->CGPA);
}
