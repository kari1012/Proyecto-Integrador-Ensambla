#ifndef RBTREE_H
#define RBTREE_H
#include <iostream>
#include <stack>
using namespace std;

enum colors {
	RED, BLACK
};

// Nodos del arbol:

template <typename T>
class rbnode {
public:
	// Esta clase es para ser usada por otras clases.
	// Por eficiencia se hacen los atributos publicos.
	T key;
	rbnode<T> *p, *left, *right;
	enum colors color;

	// Constructor por omision.

	rbnode() {
	};

	// Constructor por copia del nodo.

	rbnode(const rbnode<T> * obj, const rbnode<T> * objNil, rbnode<T> * parent, rbnode<T> * nilPtr) {
	}

	// Inicializacion de datos miembro.

	rbnode(const T& k, rbnode<T> *w = NULL, rbnode<T> *y = NULL, rbnode<T> *z = NULL, enum colors c = RED) :
		key(k), p(w), left(y), right(z), color(c) {
	};

	~rbnode() {

	}
};

// Arbol:

template <typename T>
class rbtree {
public:

	rbtree();
	// Constructor (crea un arbol vacio)

	rbtree(const rbtree<T>& obj);
	// Constructor copia

	~rbtree();
	// Destructor (borra el arbol)

	void inorderTreeWalk(rbnode<T>* x, stack<T> & pila);
	// Efectua un recorrido en orden del subarbol cuya raíz es apuntada
	// por x. En cada visita apila la llave de cada nodo y su color.
	// Es decir, cada vez que se llega a un nodo se ejecutan las 
	// instrucciones pila.push(x->key); y luego pila.push(colorDeX).
	// Para efectos de la tarea, si el color del nodo es rojo, 
	// ponga en la pila un 0, y si es negro, ponga un 1.
	// Si se hace correctamente, al finalizar el mŽtodo la pila deber’a 
	// contener las llaves de los nodos del sub‡rbol (y su color) 
	// ordenadas de mayor a menor.

	rbnode<T>* treeSearch(const T& k);
	// Busca la llave recursivamente, si la encuentra devuelve un 
	// puntero al nodo que la contiene, sino devuelve NULL.

	rbnode<T>* iterativeTreeSearch(const T& k);
	// Igual que en el anterior pero usa un procedimiento iterativo.

	rbnode<T>* treeMinimum();
	// Devuelve el nodo con la llave menor.
	// Si el arbol esta vacio devuelve NULL.

	rbnode<T>* treeMaximum();
	// Devuelve el nodo con la llave mayor.
	// Si el arbol esta vacio devuelve NULL.

	rbnode<T>* treeSuccessor(const rbnode<T>* x);
	// Devuelve el nodo cuya llave es la siguiente mas grande que 
	// la del nodo x. Si no existe tal nodo devuelve NULL.

	void treeInsert(rbnode<T>* z); //aux es y, actual es x.
								   // Inserta el nodo z en la posicion que le corresponde en el arbol.

	rbnode<T>* treeDelete(rbnode<T>* z);
	// Saca del arbol la llave contenida en el nodo apuntado por z.
	// Devuelve la direccion del nodo eliminado para que se pueda 
	// disponer de el.

	rbnode<T> * getRoot() const {
		return this->root;
	};

	// Devuelve la raiz del arbol. (Para efectos de revision de la tarea).

	rbnode<T> * getNil() const {
		return this->nil;
	};
	// Devuelve T.nil. (Para efectos de revision de la tarea).

private:

	rbnode<T> *root; // raiz del arbol
	rbnode<T> *nil; // nodo nil (hoja) del arbol

	void rbInsertFixup(rbnode<T> *z);
	void leftRotate(rbnode<T> *z);
	void rightRotate(rbnode<T> *z);
};

template<typename T>
rbtree<T>::rbtree() {
	root = new rbnode<T>();
	nil = new rbnode<T>();
	root->p = nil;
	root->color = BLACK;
	nil->color = BLACK;
	root->left = nil;
	root->right = nil;
}

template<typename T>
rbtree<T>::rbtree(const rbtree<T>& obj) {
	//no se pide implementacion de contructor de copias
}

template<typename T>
rbtree<T>::~rbtree() {
	if(root != nullptr){
		if (root->right != nil)
			rbtree();
		if (root->left != nil)
			rbtree();
		delete root;
	}
}

template<typename T>
void rbtree<T>::inorderTreeWalk(rbnode<T>* x, stack<T>& pila) {
	if (x != NULL && x != nil) {
		inorderTreeWalk(x->left, pila);
		pila.push(x->key);
		pila.push(x->color);
		inorderTreeWalk(x->right, pila);
	}
}

template<typename T>
rbnode<T>* rbtree<T>::treeSearch(const T & k) {
	if (root == NULL || k == root->key) {
		return root;
	}
	if (k < root->key) {
		root = root->left;
		return treeSearch(k);
	}
	else {
		root = root->right;
		return treeSearch(k);
	}
}

template<typename T >
rbnode<T>* rbtree<T>::iterativeTreeSearch(const T & k) {
	rbnode<T> *t = root;
	while (t != NULL && k != t->key) {
		if (k < t->key) {
			t = t->left;
		}
		else {
			t = t->right;
		}
	}
	return t;
}

template <typename T >
rbnode<T>* rbtree<T>::treeMinimum() {
	rbnode<int> *t = root->right;
	while (t->left != nil)
		t = t->left;
	return t;
}

template <typename T >
rbnode<T>* rbtree<T>::treeMaximum() {
	rbnode<int> *t = root;
	while (t->right != nil)
		t = t->right;
	return t;
}

template <typename T >
rbnode<T>* rbtree<T>::treeSuccessor(const rbnode<T>* x) {
	rbnode<T> *y;
	rbnode<T> *p = x->right;
	if (x->left != nil) {
		while (p->left != nil)
			p = p->left;
		return p;
	}
	y = x->p;
	while (y != nil && x == y->right) {
		x = y;
		y = y->p;
	}
	return y;
}

template<typename T>
void rbtree<T>::treeInsert(rbnode<T>* z) {
	rbnode<T> *y = nil;
	rbnode<T> *x = root;

	if (root == nullptr) {
		root->key = z->key;
	}
	else {

		while (x != nil) { //se pone el apuntador a apuntar al nodo donde deberia insertarse
			y = x;
			if (z->key < x->key) {
				x = x->left;
			}
			else {
				x = x->right;
			}
		}
		z->p = y;
		if (y == nil) {
			root = z;
		}
		else {
			if (z->key < y->key)//pongo a Y a puntar a Z como su hijo derecho o izquierdo
				y->left = z;
			else
				y->right = z;
		}

		z->left = nil;
		z->right = nil;
		z->color = RED;
		rbInsertFixup(z);
	}
}
//método usado por la función insertar

template<typename T>
void rbtree<T>::rbInsertFixup(rbnode<T>* z) {
	rbnode<T> *y;
	while (z->p->color == RED) {
		if (z->p == z->p->p->left) { // se pone a z a apuntar al tio del él
			y = z->p->p->right;

			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->right) {
					z = z->p;
					leftRotate(z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				rightRotate(z->p->p);
			}
		}
		else {
			//// igual que la clausula anterior
			y = z->p->p->left;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {

				if (z == z->p->left) {//caso 2 pasa a caso 3
					z = z->p;
					rightRotate(z);
				}
				z->p->color = BLACK; //caso 3
				z->p->p->color = RED;
				leftRotate(z->p->p);
			}
		}
		root->color = BLACK;
	}
}

//método usado por la función rbInserFixup
template<typename T>
void rbtree<T>::leftRotate(rbnode<T>* x) {
	rbnode<T> *y = x->right;
	x->right = y->left;
	if (y->left != nil) {
		y->left->p = x;
	}
	y->p = x->p;
	if (x->p == nil) {
		root = y;
	}
	else {
		if (x == x->p->left) {
			x->p->left = y;
		}
		else {
			x->p->right = y;
		}
	}
	y->left = x;
	x->p = y;
}

//método usado por la función rbInserFixup

template<typename T>
void rbtree<T>::rightRotate(rbnode<T>* x) {
	rbnode<T> *y = x->left;
	x->left = y->right; //doy los hijos que corresponden en adopcion al hacer la rotacion
	if (y->right != nil) {
		y->right->p = x;
	}
	y->p = x->p;
	if (x->p == nil) {
		root = y;
	}
	else {
		if (x == x->p->right) {
			x->p->right = y;
		}
		else {
			x->p->left = y;
		}
	}
	y->right = x;
	x->p = y;
}


#endif /* RBTREE_H */




