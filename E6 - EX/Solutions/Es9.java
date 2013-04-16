class Es9 {

	/**
	 * Costruire la funzione f qui sotto riportata che presa in ingresso una
	 * matrice quadrata di dimensione N, torna in uscita un array contenente gli
	 * elementi del bordo che partono da quello in basso a destra, proseguendo
	 * in senso antiorario fino a quello in alto a sinistra.
	 * 
	 * Come riferimento si consideri che la funzione deve passare il test sotto
	 * riportato.
	 **/

	public static int[] f(int[][] m) {
		int[] a = new int[2 * m.length - 1];
		int i;
		for (i = 0; i < m.length; i++) {
			a[i] = m[m.length - 1 - i][m.length - 1];
			a[i + a.length / 2] = m[0][m.length - 1 - i];
		}
		return a;
	}

    public static boolean test(){
        int[][] m1=new int[][]{
            new int[]{10,20,30,40,50},
            new int[]{11,21,31,41,51},
            new int[]{12,22,32,42,52},
            new int[]{13,23,33,43,53},
            new int[]{14,24,34,44,54}
        };
        int[][] m2=new int[][]{
            new int[]{10,20},
            new int[]{11,21}
        };
        int[][] m3=new int[][]{
            new int[]{10,20,30,40},
            new int[]{11,21,31,41},
            new int[]{12,22,32,42},
            new int[]{13,23,33,43}
        };
        return arrayEquals(f(m1),new int[]{54,53,52,51,50,40,30,20,10}) &&
                arrayEquals(f(m2),new int[]{21,20,10}) &&
                arrayEquals(f(m3),new int[]{43,42,41,40,30,20,10});
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
		System.out.println("Confronto: " + arrayToString(a) + " " + arrayToString(b));
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
