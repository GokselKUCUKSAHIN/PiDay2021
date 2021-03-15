#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int getRandomInt(int min, int max);
int gcd(int a, int b);
double calculate(int coPrime, int total);
double estimateNumberPI(void);

int main(void)
{
  srand(time(0));
  double piE = estimateNumberPI();
  printf("PIE estimate = %.15f\n", piE);
  return 0;
}

int getRandomInt(int min, int max)
{
  return (rand() % 90000) + 10000;
}

int gcd(int a, int b)
{
  if (b > a)
  {
    int temp = a;
    a = b;
    b = temp;
  }
  int m = a % b;
  if (m == 0)
  {
    return b;
  }
  else
  {
    return gcd(b, m);
  }
}

double calculate(int coPrime, int total)
{
  const double ratio = coPrime / (double)total;
  return sqrt(6 / ratio);
}

double estimateNumberPI()
{
  int coPrime = 0, total = 0, i;
  for (i = 0; i < 1000000000; i++)
  {
    const int first = getRandomInt(10000, 100000);
    const int second = getRandomInt(10000, 100000);
    if(gcd(first, second) == 1) 
    {
      coPrime++;
    }
    total++;
  }
  return calculate(coPrime, total);
}
