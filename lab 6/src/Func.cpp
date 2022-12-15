#include <Func.hpp>
#include <cmath>

namespace zer {
	int DifferenceOfMinAndMax(int x, int y) {
		//нахождение суммы цифр максимального
		int summax = 0;
		int summin = 0;
		int dif;
		while (x != 0)
		{
			summax += x % 10;
			x /= 10;
		}

		//нахождение суммы цифр минимального

		while (y != 0)
		{
			summin += y % 10;
			y /= 10;	
		}
		dif = abs(summax - summin);
		return dif;
	}
}