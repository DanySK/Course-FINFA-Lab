class E4{

    /** Realizzare la funzione mat qui sotto riportata che dato in ingresso una matrice 
      * nxn di nome m rappresentata come array di array (dove m[i] rappresenta l'i-esima
      * riga), azzera la metà della matrice sopra la diagonale secondaria.
      * Ad esempio, la matrice
      *
      *     3333
      *     0313
      *     1233
      *     1123
      *
      * Deve essere trasformata in
      *
      *     0003
      *     0013
      *     0233
      *     1123
      *
      *
      * Si consideri anche che l'esecuzione del test (eseguita dal metodo main) deve riportare 
      * il risultato true. Come ausilio per il debugging, si noti che la funzionalità arrayEquals
      * sotto riportata stampa i due array che sta confrontando!
      **/

	public static int[][] mat(int[][] m) {
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < m.length; j++) {
				if (i < m.length - 1 - j) {
					m[i][j] = 0;
				}
			}
		}
		return m;
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
                arrayEquals(m2[0],new int[]{0,0,0,0,3}) &&
                arrayEquals(m2[1],new int[]{0,0,0,1,3}) &&
                arrayEquals(m2[2],new int[]{0,0,3,3,1}) &&
                arrayEquals(m2[3],new int[]{0,1,2,3,1}) &&
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
