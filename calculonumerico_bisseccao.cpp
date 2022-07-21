#include <iostream>
#include <math.h>
#include <stdio.h>
//declaração de variáveis
using namespace std;

double f(double x){
	return (x*log(x))-3.2; //Função dedicada para o cálculo da função
}

int main(){
	setlocale(LC_ALL, ""); //Permite acentuação portuguesa
	float a, b, x, M, E=0.01; //a e b são intervalos iniciais e finais, x são os novos limites divididos ao meio, e o E é a tolerância de erro
	int k=1; //Contagem de iteração
	int limite=100; //Limite de contagem de iteração
	
	cout<<"Informe o valor inicial: ";
	cin>>a;
	cout<<"Informe o valor final: ";
	cin>>b;
	
	M = f(a);
	x=(a+b)/2; //Separa a diferença dos intervalos no meio
	cout<<"\nNa iteração "<<k<<" O limite inferior é "<<a<<" e o limite superior é "<<b<<endl;
	while (fabs(b-a) > E){ //Pega o módulo da função f() aplicada no novo intervalo e vê se está dentro da margem de erro
		if((M*f(x))>0){
			a=x; //Se tiver positivo, o limite inferior é dividido
			
		}
		else{
			b=x; //Se tiver negativo, o limite superior é dividido
		}
		cout<<"Na iteração "<<k+1<<" O limite inferior é "<<a<<" e o limite superior é "<<b<<endl;
		x=(a+b)/2; //Faz novamente a metade do intervalo para a próxima sequência
		k++; //Acrescenta contagem na iteração
		if (k==limite) //Se a contagem extrapolar o limite, encerre e diga que não existe raízes
		{
			cout<<"RAIZ INEXISTENTE NESTE INTERVALO"<<endl;
			break;
		}
	}
	
	cout<<"a raiz aproximada é: "<<x<<" e seu erro é de: "<<f(x)<<"\nNúmero de iterações: "<<k;;
	
}
