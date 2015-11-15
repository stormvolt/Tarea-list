#include <iostream>
 
#include "list.h"
#include "list.cpp"
 
using namespace std;
 
int main()
{
	List<int> list_1;
	List<int> list_2;
	list_1.add_head(1);
	list_1.add_head(2);
	list_1.add_head(3);
	list_2.add_head(4);
	list_2.add_head(5);
	list_2.add_head(6);
    
	int element;
	int pos;
 
	cout<< "Lista A:";
	list_1.print();
	cout<<"\n";
	cout<< "Lista B:";
	list_2.print();

	cout << "Agrega un elemento a la cabeza de A: " << endl;
	cin >> element;
	list_1.add_head(element);
	list_1.print();

	cout << "Agrega un elemento al final de A: " << endl;
	cin >> element;
	list_1.add_end(element);
	list_1.print();
 
	cout << "Lista A invertida: " << endl;
	list_1.invert();
	list_1.print();
 
	cout << "Lista A ordenada: " << endl;
	list_1.sort();
	list_1.print();
 
  
	cout << "Busca un elemento en A: " << endl;
	cin >> element;
	int r= list_1.search(element);
	if(r != 0)
	{	
		cout<<"El dato se encuentra en la posición: " << list_1.search(element)<<"\n";
	}
 
	cout << "Elimina un elemento por dato en A: " << endl;
	cin >> element;
	list_1.del_by_data(element);
	list_1.print();
 
	cout << "Elimina un elemento por posición en A: " << endl;
	cin >> pos;
	list_1.del_by_position(pos);
	list_1.print();

	cout << "Listas A y B concatenadas: " << endl;
	list_1.concat(list_2);
	list_1.print();

	cout<<"A + B:  ";
	List <int> c;
	c= list_1+list_2;
	c.print();


	cout<<"A - B:  ";
	List <int> d;
	d= list_1-list_2;
	d.print();
 
 
	list_1.del_all();
	list_1.print();
 
	return 0;
}
