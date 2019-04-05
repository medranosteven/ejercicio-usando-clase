//hecho por jesus steven medrano carballo
//carnet: MC18055
//areas y perimetros de figuras geometricas usando clase

#include <iostream>
#include <windows.h>
#include<conio.h>

using namespace std;

class Figura{
	
	private: 
			float base;
			float altura;
	public: 
			Figura(){
				this->base=0;
				this->altura=0;
			}
			Figura(float b, float a) //polimorfismo: usar un metodo con dos funcionabilidades diferentes
			{
				this->base=b;
				this->altura=a;
			}
			void setbase(float b){
				this->base=b;
			}
			float getbase(){
				return this->base;
			}
			void setaltura(float a){
				this->altura=a;
			}
			float getaltura(){
				return this->altura;
			}
			virtual float area()=0;		//la funcion virtual significa que despues se puede sobreescribir sobre el
			virtual float perimetro()=0;	//cualquier otra clase puede generar modificaciones con esta funcion
};

class Color{
	public:
			void Colorear(){
				cout<<"estoy pintando"<<endl;
			}
};

class Rectangulo:public Figura, public Color //rectangulo es hijo de figura y recibe todas sus propiedades y metodos
{
	public:
		float area(){
			return getbase()* getaltura();
		}
		float perimetro(){
			return 2*getbase()+2*getaltura();
		}
	void ImprimirR(){
		for(int i=0; i<getaltura(); i++){
			cout<<endl;
			for(int j=0; j<getbase(); j++){
				cout<<"* ";
			}
		}
		
	}
};

class Cuadrado:public Figura //cuadrado es hijo de rectangulo y recibe todas sus propiedades y metodos
{
	public:
		float area(){
			return getbase()*getbase();
		}
		float perimetro(){
			return 4*getbase();
		}
	void ImprimirR(){
		for(int i=0; i<getbase(); i++){
			cout<<endl;
			for(int j=0; j<getbase(); j++){
				cout<<"* ";
			}
		}
		
	}
};

class Triangulo:public Figura //triangulo recibe de los demas metodos pero es diferente
{
	public:
		float area(){
			return getbase()*getaltura()*1/2;
		}
		float perimetro(){
			return getbase()+getaltura()+getaltura();
		}
		void ImprimirR(){
		for(int i=0; i<=getbase(); i++){
			cout<<endl;
			for(int j=0; j<=i; j++){
				cout<<"*";
			}
		}
		
	}
};

class PrincipalR{
	public:
	PrincipalR(){
		Rectangulo *r= new Rectangulo();
		r->setbase(6);
		r->setaltura(4);
		cout<<r->getbase()<<"   "<<r->getaltura()<<endl;
		cout<<"Area: "<<r->area()<<endl;
		cout<<"Perimetro: "<<r->perimetro()<<endl;
		r->ImprimirR();
	}
};

class PrincipalC{
	public:
	PrincipalC(){
		Cuadrado *c= new Cuadrado();
		c->setbase(4);
		cout<<c->getbase()<<"   "<<endl;
		cout<<"Area: "<<c->area()<<endl;
		cout<<"Perimetro: "<<c->perimetro()<<endl;
		c->ImprimirR();
	}
};

class PrincipalT{
	public:
	PrincipalT(){
		 Triangulo *t= new Triangulo();
		 t->setbase(5);
		 t->setaltura(3);
		cout<<t->getbase()<<"   "<<t->getaltura()<<endl;
		cout<<"Area: "<<t->area()<<endl;
		cout<<"Perimetro: "<<t->perimetro()<<endl;
		t->ImprimirR();
	}
};

int main() {
	//Figura *t/*declarar*/=new Figura(); //instanciar un objeto
	/*t->setbase(4);
	t->setaltura(2);
	cout<<t->getbase();
	cout<<t->getaltura();*/
	
	cout<<"rectangulo"<<endl;
	PrincipalR *pro=new PrincipalR();
	cout<<endl<<endl;
	
	cout<<"cuadrado"<<endl;
	PrincipalC *pr=new PrincipalC();
	cout<<endl<<endl;
	
	cout<<"triangulo"<<endl;
	PrincipalT *p=new PrincipalT();
	
	getch ();
	return 0;
}
