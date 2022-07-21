#include <iostream>
#include <math.h>
#include <stdio.h>
//declara��o de vari�veis
using namespace std;

double f(double x){
	return (x*log(x))-3.2; //Fun��o dedicada para o c�lculo da fun��o
}

int main(){
	setlocale(LC_ALL, ""); //Permite acentua��o portuguesa
	float a, b, x, M, E=0.01; //a e b s�o intervalos iniciais e finais, x s�o os novos limites divididos ao meio, e o E � a toler�ncia de erro
	int k=1; //Contagem de itera��o
	int limite=100; //Limite de contagem de itera��o
	
	cout<<"Informe o valor inicial: ";
	cin>>a;
	cout<<"Informe o valor final: ";
	cin>>b;
	
	M = f(a);
	x=(a+b)/2; //Separa a diferen�a dos intervalos no meio
	cout<<"\nNa itera��o "<<k<<" O limite inferior � "<<a<<" e o limite superior � "<<b<<endl;
	while (fabs(b-a) > E){ //Pega o m�dulo da fun��o f() aplicada no novo intervalo e v� se est� dentro da margem de erro
		if((M*f(x))>0){
			a=x; //Se tiver positivo, o limite inferior � dividido
			
		}
		else{
			b=x; //Se tiver negativo, o limite superior � dividido
		}
		cout<<"Na itera��o "<<k+1<<" O limite inferior � "<<a<<" e o limite superior � "<<b<<endl;
		x=(a+b)/2; //Faz novamente a metade do intervalo para a pr�xima sequ�ncia
		k++; //Acrescenta contagem na itera��o
		if (k==limite) //Se a contagem extrapolar o limite, encerre e diga que n�o existe ra�zes
		{
			cout<<"RAIZ INEXISTENTE NESTE INTERVALO"<<endl;
			break;
		}
	}
	
	cout<<"a raiz aproximada �: "<<x<<" e seu erro � de: "<<f(x)<<"\nN�mero de itera��es: "<<k;;
	
}
