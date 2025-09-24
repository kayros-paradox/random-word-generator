#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "stdbool.h"
#include "ctype.h"

bool  isnbr(char *str);	  // Проверка на целое.

int main(int argc, char **argv)
{
  const char  *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int		  index;
  bool		  check;

  check = argc == 2 && isnbr(argv[1]);
  srand(time(NULL));
  if (check)
  {
	if (strlen(argv[1]) > 9)
	  printf("Пожалуйста введите число меньшей длины");
	else 
	{
	  index = atoi(argv[1]);
	  while (index-- > 0)
		printf("%c", alpha[rand() % 26]);
	}
  }
  else
  {
	printf("Справка: необходимо указать количество букв.\n");
	printf("Пример: %s <целое число>", argv[0]);
  }
  printf("\n");
  return (0);
}


bool  isnbr(char *str)
{
  bool	res;

  res = true;
  while (*str != '\0')
  {
	res = res && isdigit(*str);
	str++;
  }
  return (res);
}

