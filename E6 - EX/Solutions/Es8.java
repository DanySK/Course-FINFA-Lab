class Es8{

    /** Realizzare la funzione mat qui sotto riportata che dato in ingresso una matrice 
      * nxn di nome m rappresentata come array di array (dove m[i] rappresenta l'i-esima
      * riga), crea una nuova struttura pari alla matrice di ingresso meno il triangolo sopra la diagonale principale.
	  * Cioè, data la matrice
      *
      *     3333
      *     0313
      *     1233
      *     1123
      *
      * Deve essere generata 
      *
      *     3
      *     03
      *     123
      *     1123
      *
      *
      * Si consideri anche che l'esecuzione del test (eseguita dal metodo main) deve riportare 
      * il risultato true. Come ausilio per il debugging, si noti che la funzionalità arrayEquals
      * sotto riportata stampa i due array che sta confrontando!
      **/

      
	public static int[][] mat(int[][] m) {
		int[][] m1 = new int[m.length][];

		for (int i = 0; i < m.length; i++) {
			m1[i] = new int[i + 1];
			for (int j = 0; j < m1[i].length; j++) {
				m1[i][j] = m[i][j];
			}
		}
		for (int i = 0; i < m.length; i++) {
			System.out.println("m1[" + i + "] = " + arrayToString(m1[i]));
		}
		return m1;
	}
      
    public static boolean test(){
            int[][] m=new int[][]{
                        new int[]{3,3,3,3,3},
                        new int[]{0,3,1,1,3},
                        new int[]{1,2,3,3,1},
                        new int[]{0,1,2,3,1},
                        new int[]{1,1,2,3,0}
            };
            int[][] m2=mat(m);
            return 
                arrayEquals(m2[0],new int[]{3}) &&
                arrayEquals(m2[1],new int[]{0,3}) &&
                arrayEquals(m2[2],new int[]{1,2,3}) &&
                arrayEquals(m2[3],new int[]{0,1,2,3}) &&
                arrayEquals(m2[4],new int[]{1,1,2,3,0});
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
