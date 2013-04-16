class Es1{

	// riconoscitore in forma iterativa grammatica {0}{2}^n{3}^n
	public static boolean ric(int[] a) {
		int i;
		int n = 0;
		for (i = 0; i < a.length && a[i] == 0; i++);
		for (; i < a.length && a[i] == 2; i++, n++);
		for (; i < a.length && a[i] == 3; i++, n--);
		if (n == 0 && i == a.length) {
			return true;
		}
		return false;
	}
   
	public static boolean test() {
		return ric(new int[] {})
				&& ric(new int[] { 0, 0, 0 })
				&& ric(new int[] { 0, 0, 0, 2, 2, 3, 3 })
				&& ric(new int[] { 2, 2, 2, 3, 3, 3 })
				&& ric(new int[] { 2, 3 })
				&& !ric(new int[] { 2, 2, 2, 3, 3 })
				&& !ric(new int[] { 1, 0 })
				&& !ric(new int[] { 2, 2, 3, 3, 3 })
				&& !ric(new int[] { 0, 0, 0, 2, 2, 0, 3, 3 });
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
