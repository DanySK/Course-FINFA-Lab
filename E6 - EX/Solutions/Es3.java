class Es3 {
	// Raddoppia i primi n numeri in a
	public static int[] radN(int[] a, int n) {
		if (n > a.length) {
			n = a.length;
		}
		int[] b = new int[a.length + n];
		int k = n;
		int i;
		for (i = 0; i < a.length && n > 0; i++) {
			b[i * 2] = a[i];
			b[i * 2 + 1] = a[i];
			n--;
		}
		for (; i < a.length; i++) {
			b[i + k] = a[i];
		}
		return b;
	}

	public static boolean test() {
		return arrayEquals(radN(new int[] { 10, 20, 30, 40, 50 }, 0), new int[] { 10, 20, 30, 40, 50 })
				&& arrayEquals(radN(new int[] { 10, 20, 30, 40, 50 }, 1), new int[] { 10, 10, 20, 30, 40, 50 })
				&& arrayEquals(radN(new int[] { 10, 20, 30, 40, 50 }, 2), new int[] { 10, 10, 20, 20, 30, 40, 50 })
				&& arrayEquals(radN(new int[] { 10, 20, 30, 40, 50 }, 5), new int[] { 10, 10, 20, 20, 30, 30, 40, 40, 50, 50 })
				&& arrayEquals(radN(new int[] { 10, 20, 30, 40, 50 }, 8), new int[] { 10, 10, 20, 20, 30, 30, 40, 40, 50, 50 });
	}

	public static void main(String[] s) {
		System.out.println("" + test());
	}

	public static String arrayToString(int[] a) {
		String s = "(";
		for (int i = 0; i < a.length; i++) {
			s = s + a[i];
			if (i != a.length - 1) {
				s = s + ",";
			}
		}
		return s + ")";
	}

	public static boolean arrayEquals(int[] a, int[] b) {
		if (a.length != b.length) {
			return false;
		}
		for (int i = 0; i < a.length; i++) {
			if (a[i] != b[i]) {
				return false;
			}
		}
		return true;
	}
}
