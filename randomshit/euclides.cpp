#include "stdc++.h"
using namespace std;

int MDC(int a, int b)
{
	if (b == 0)
		return a;
	
	return MDC(b, a%b); //algoritmo de euclides para achar o mdc
}