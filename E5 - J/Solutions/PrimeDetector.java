class PrimeDetector {

  static boolean isPrime(int n) {
    if (n == 2 || n == 3) {
      return true;
    }
    if (n < 2 || n % 2 == 0) {
      return false;
    }
    int i = 3;
    for (; i < n / 2 && n % i != 0; i+=2);
    return i == n/2 || i == n/2 + 1;
  }

  static boolean test() {
    return isPrime(Integer.MAX_VALUE) &&
      isPrime(2) &&
      isPrime(7) &&
      isPrime(5) &&
      isPrime(100109) &&
      !isPrime(0) &&
      !isPrime(-100109) &&
      !isPrime(100111) &&
      !isPrime(1) &&
      !isPrime(Integer.MAX_VALUE-1);
  }

  public static void main(String[] a) {
    System.out.print("Running test... ");
    boolean testResult = test();
    System.out.println("done. Result is "+testResult);
    if(testResult && a.length > 0) {
      System.out.print("Checking if "+a[0]+" is a prime number: ");
      if(isPrime(Integer.parseInt(a[0]))){
	System.out.println("yes, it is.");
      } else {
	System.out.println("no, it is not.");
      }
    }
  }
  
}
