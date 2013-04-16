class E4{

	/*
	 * Realizzare la funzione int[][] mat(int, int) che, dati due interi
	 * rappresentanti rispettivamente la dimensione della matrice ed un valore,
	 * crea una matrice quadrata grande quanto indicato i cui valori sono tutti
	 * zero eccetto le due diagonali, che devono avere come valore quello del
	 * secondo argomento.
	 * 
	 * Esempi:
	 * 
	 * mat(1,2)
	 * 2
	 * 
	 * mat(2,0)
	 * 0 0
	 * 0 0
	 * 
	 * mat(3,1)
	 * 1 0 1
	 * 0 1 0
	 * 1 0 1
	 * 
	 * mat(4,8)
	 * 8 0 0 8
	 * 0 8 8 0
	 * 0 8 8 0
	 * 8 0 0 8
	 * 
	 * 
	 * Si consideri anche che l'esecuzione del test (eseguita dal metodo main)
	 * deve riportare il risultato true. Per aiutarsi con questo esercizio,
	 * viene fornito un esercizio analogo risolto nel file Example.java
	 */
      
    public static int[][] mat(int size, int n){
            return new int[10][10];
    }
      
	public static boolean test() {
		int[][] m2 = mat(5, 6);
		return arrayEquals(mat(1, 0)[0], new int[] { 0 })
				&& arrayEquals(mat(1, 1)[0], new int[] { 1 })
				&& arrayEquals(mat(2, 1)[0], new int[] { 1, 1 })
				&& arrayEquals(mat(2, 1)[1], new int[] { 1, 1 })
				&& arrayEquals(m2[0], new int[] { 6, 0, 0, 0, 6 })
				&& arrayEquals(m2[1], new int[] { 0, 6, 0, 6, 0 })
				&& arrayEquals(m2[2], new int[] { 0, 0, 6, 0, 0 })
				&& arrayEquals(m2[3], new int[] { 0, 6, 0, 6, 0 })
				&& arrayEquals(m2[4], new int[] { 6, 0, 0, 0, 6 });
	}

	public static void main(String[] s) {
		System.out.println("" + test());
	}

	static String arrayToString(int[] a) {
		String s = "";
		for (int i = 0; i < a.length; i++) {
			s += a[i] + ";";
		}
		return s;
	}

	static boolean arrayEquals(int[] a, int[] b) {
		System.out.println("Comparing " + arrayToString(a) + " with " + arrayToString(b));
		if (a.length != b.length)
			return false;
		for (int i = 0; i < a.length; i++) {
			if (a[i] != b[i]) {
				return false;
			}
		}
		return true;
	}


}
