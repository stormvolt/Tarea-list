#include "list.h"
 
using namespace std;
 
// Constructor por defecto
template<typename T>
List<T>::List()
{
	m_num_nodes = 0;
	m_head = NULL;
}



// Destructor 
template<typename T>
List<T>::~List()
{
}


// Insertar al inicio
template<typename T>
void List<T>::add_head(T data_)
{
	Node<T> *new_node = new Node<T> (data_);
	Node<T> *temp = m_head;
 
	if (!m_head)
	{
		m_head = new_node;
	}
	else
	{
		new_node->next = m_head;
		m_head = new_node;
		while (temp)
		{
			temp = temp->next;
		}
	}
	m_num_nodes++;
}
 
// Insertar al final
template<typename T>
void List<T>::add_end(T data_)
{
	Node<T> *new_node = new Node<T> (data_);
	Node<T> *temp = m_head;
	if (!m_head)
	{
		m_head = new_node;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
	m_num_nodes++;
}
 
 
// Concatenar a otra List
template<typename T>
void List<T>::concat(List list)
{
	Node<T> *temp2 = list.m_head;
	while (temp2)
	{
		add_end(temp2->data);
		temp2 = temp2->next;
	}
}
 

// Eliminar todos los nodos
template<typename T>
void List<T>::del_all()
{
	m_head->delete_all();
	m_head = 0;
}

 
// Eliminar por data del nodo
template<typename T>
void List<T>::del_by_data(T data_)
{
	Node<T> *temp = m_head;
	Node<T> *temp1 = m_head->next;
	int cont = 0;
	if (m_head->data == data_)
	{
		m_head = temp->next;
	}
	else
	{
		while (temp1)
		{
			if (temp1->data == data_)
			{
				Node<T> *aux_node = temp1;
				temp->next = temp1->next;
				delete aux_node;
				cont++;
				m_num_nodes--;
			}
		temp = temp->next;
		temp1 = temp1->next;
		}
	}
	if (cont == 0)
	{
		cout << "No existe el dato " << endl;
	}
}


// Eliminar por posición del nodo
template<typename T>
void List<T>::del_by_position(int pos)
{
	Node<T> *temp = m_head;
	Node<T> *temp1 = temp->next;
	if (pos < 1 || pos > m_num_nodes)
	{
		cout << "Fuera de rango " << endl;
	}
	else if (pos == 1)
	{
		m_head = temp->next;
	}
	else
	{
		for (int i = 2; i <= pos; i++)
		{
			if (i == pos)
			{
				Node<T> *aux_node = temp1;
				temp->next = temp1->next;
				delete aux_node;
				m_num_nodes--;
			}
			temp = temp->next;
			temp1 = temp1->next;
		}
	}
}


// Llenar la Lista por teclado
template<typename T>
void List<T>::fill_by_user(int dim)
{
	T element;
	for (int i = 0; i < dim; i++)
	{
		cout << "Ingresa el elemento " << i + 1 << endl;
		cin >> element;
		add_end(element);
	}
}
 

 
// Usado por el método intersección
template<typename T>
void insert_sort(T a[], int size)
{
	T temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i-1; j>= 0 && a[j+1] < a[j]; j--)
		{
			temp = a[j+1];
			a[j+1] = a[j];
			a[j] = temp;
		}
	}
}


// Elimir números que coinciden en 2 Lists
template<typename T>
void List<T>::nointersection(List<T> list_2)
{
	Node<T> *temp = m_head;
	Node<T> *temp2 = list_2.m_head;
	// Creo otra Lista
	List intersection_list;
	int num_nodes_2 = list_2.m_num_nodes;
	int num_inter = 0;
	// Creo 2 vectores dinámicos
	T *v1 = new T[m_num_nodes];
	T *v2 = new T[num_nodes_2];
	// Lleno los vectores v1 y v2 con los datas de la lista original y segunda lista respectivamente
	int i = 0;
	while (temp)
	{
		v1[i] = temp->data;
		temp = temp->next;
		i++;
	}
	int j = 0;
	while (temp2)
	{
		v2[j] = temp2->data;
		temp2 = temp2->next;
		j++;
	}
	// Ordeno los vectores
	insert_sort(v1, m_num_nodes);
	insert_sort(v2, num_nodes_2);
	// Índice del 1er vector (v1)
	int v1_i = 0;
	// Índice del 2do vector (v2)
	int v2_i = 0;
	// Mientras no haya terminado de recorrer ambas Lists:
	while (v1_i < m_num_nodes && v2_i < num_nodes_2)
	{
		if (v1[v1_i] == v2[v2_i])
		{
			intersection_list.add_end(v1[v1_i]);
			v1_i++;
			v2_i++;
			num_inter++;
		}
		else if (v1[v1_i] < v2[v2_i])
		{
			v1_i++;
		}
		else
		{
			v2_i++;
		}
	}
	// Solo si hay alguna intersección, la elimino
	if (num_inter > 0)
	{
		Node<T> *temp3 = intersection_list.m_head;
		T *v3 = new T[intersection_list.m_num_nodes];
		int h = 0;
		while (temp3)
		{
			v3[h] = temp3->data;
			temp3 = temp3->next;
			h++;
		}
		for(int u=0; u<intersection_list.m_num_nodes ; u++ )
		{
			int borrar=search(v3[u]);	
			del_by_position(borrar);
		}
	} 
}



// Invertir la lista
template<typename T>
void List<T>::invert()
{
	Node<T> *prev = NULL;
	Node<T> *next = NULL;
	Node<T> *temp = m_head;
	while (temp)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	m_head = prev;
}
 

 
// Imprimir la Lista
template<typename T>
void List<T>::print()
{
	Node<T> *temp = m_head;
	if (!m_head)
	{
		cout << "La Lista está vacía " << endl;
	}
	else
	{
		while (temp)
		{
			temp->print();
			if (!temp->next)
			{
				cout << "NULL";
			}
			temp = temp->next;
		}
	}
	cout << endl << endl;
}


// Buscar el dato de un nodo
template<typename T>
int List<T>::search(T data_)
{
	Node<T> *temp = m_head;
	int cont = 1;
	int cont2 = 0;
	while (temp)
	{
		if (temp->data == data_)
		{
			return cont;			
			cont2++;
		}
		temp = temp->next;
		cont++;
	}
	if (cont2 == 0)
	{
		cout << "No existe el dato " << "\n";
		return 0;
	}
	cout << endl << endl;
}


// Ordenar de manera ascendente
template<typename T>
void List<T>::sort()
{
	T temp_data;
	Node<T> *aux_node = m_head;
	Node<T> *temp = aux_node;
	while (aux_node) 
	{
		temp = aux_node;
		while (temp->next)
		{
			temp = temp->next;
			if (aux_node->data > temp->data)
			{
				temp_data = aux_node->data;
				aux_node->data = temp->data;
				temp->data = temp_data;
			}
		}
		aux_node = aux_node->next;
	}
}


// Sobrecarga del operador +
template<typename T>
List<T> operator+ (List<T> a, List<T> b)
{
	List<T> c;
 	c.concat(a);
	c.concat(b);
	return c;
}


// Sobrecarga del operador -
template<typename T>
List<T> operator- (List<T> a, List<T> b)
{
	List<T> c;
	c.concat(a);
 	c.nointersection(b);
	return c;
}



