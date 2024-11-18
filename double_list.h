#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

// Definición del nodo de la lista doblemente enlazada
typedef struct Nodo {
    int dato;
    struct Nodo* anterior;
    struct Nodo* siguiente;
} Nodo;

// Funciones para la lista doblemente enlazada
Nodo* crear_nodo(int dato);
void insertar_al_inicio(Nodo** inicio, int dato);
void insertar_al_final(Nodo** inicio, int dato);
void insertar_en_posicion(Nodo** inicio, int dato, int posicion);
void eliminar_por_dato(Nodo** inicio, int dato);
Nodo* buscar_por_dato(Nodo* inicio, int dato);
void imprimir_adelante(Nodo* inicio);
void imprimir_atras(Nodo* inicio);
void liberar_lista(Nodo** inicio);

#endif // DOUBLE_LIST_H
