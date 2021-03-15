public class Main
{

  public static void main(String[] args)
  {
    System.out.println(estimateNumberPI());
  }

  private static int getRandomInt(int min, int max)
  {
    return (int) Math.floor((Math.random() * (max - min)) + min);
  }

  private static double estimateNumberPI()
  {
    int coPrime = 0;
    int total = 0;
    for (int i = 0; i < 1_000_000_000; i++)
    {
      // 1 Mil times
      int firstNumber = getRandomInt(10_000, 100_000);
      int secondNumber = getRandomInt(10_000, 100_000);
      if (gcd(firstNumber, secondNumber) == 1)
      {
        coPrime++;
      }
      total++;
    }
    return calculate(coPrime, total);
  }

  private static double calculate(int coPrime, int total)
  {
    // c / t = 6 / pi^2
    double ratio = coPrime / (double) total;
    return Math.sqrt(6 / ratio);
  }

  private static int gcd(int a, int b)
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
    } else
    {
      return gcd(b, m);
    }
  }
}
