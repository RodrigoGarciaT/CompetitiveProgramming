#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n;
	cin>>n;
	ll m, equation;
	m = (-1+sqrt(1+4*(n+1)))/2;
	equation = (m*(m+1)-1);

	if( equation == n){
		cout<<"Jane"<<endl;
	} else if(equation+m+1>=n){
		cout<<"John"<<endl;
	}else{
		cout<<"Jane"<<endl;
	}

/*

patron

empezando en n = 1 el patron de respuestas es el siguiente
jane john john jane jane john john john jane jane jane john john john john

1 jane 2 john 2 jane 3john 3jane 4john 4jane

 1 + 2 + 2 + 3 + 3 + 4 + 4

 1+ 2*2 + 2*3 +2* 4

 1+ 2(2+3+4)
n = 1+2(2+3+4)

(2+3+4) = sumatoria hasta m -1


n = 1+ 2(m(m+1)/2 -1)
(n-1) = m(m+1)-2
(n+1)= m(m+1)
(n+1) = m^2+m
m^2 + m -(n+1) = 0

se resuelve con la ecuacion cuadratica y se aproxima m
checamos la ecuacion y si es = a m gana jane porque la secuencia termina en jane

si no checamos si termina en la primera o en la segunda parte de la siguiente secuencia
si termina en la primera gana john, si no gana jane

a = 1
b = 1
c = (n+1)

	// f m m f f m m m f f f m m m m

*/
}
