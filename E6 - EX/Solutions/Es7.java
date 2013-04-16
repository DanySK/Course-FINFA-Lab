class Es7{

    /** Realizzare la funzione mat qui sotto riportata che dato in ingresso una matrice 
      * nxn di nome m rappresentata come array di array (dove m[i] rappresenta l'i-esima
      * riga), ritorna la somma degli elementi della matrice trascurandone l'orlo.
      * Ad esempio, l'orlo della matrice
      *
      *     3333
      *     0313
      *     1233
      *     1123
      *
      * e' costitutito dagli elementi 3,3,3,3,3,3,3,2,1,1,1,0, quindi la somma degli altri è 9.
      * Si consideri anche che l'esecuzione del test (eseguita dal metodo main) deve riportare 
      * il risultato true. Come ausilio per il debugging, si noti che la funzionalità arrayEquals
      * sotto riportata stampa i due array che sta confrontando!
      **/

	public static int mat(int[][] m) {
		int sum = 0;
		for (int i = 1; i < m.length - 1; i++) {
			for (int j = 1; j < m.length - 1; j++) {
				sum += m[i][j];
			}
		}
		return sum;
	}
      
    public static boolean test(){
            int[][] m=new int[][]{
                        new int[]{3,3,3,3,3},
                        new int[]{0,3,1,1,3},
                        new int[]{1,2,3,3,1},
                        new int[]{0,1,2,3,1},
                        new int[]{1,1,2,3,0}
            };
            return mat(m)==19;
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
