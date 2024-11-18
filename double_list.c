#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

// Crear un nodo
Nodo* crear_nodo(int dato) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo_nodo) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    nuevo_nodo->dato = dato;
    nuevo_nodo->anterior = NULL;
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

// Insertar al inicio
void insertar_al_inicio(Nodo** inicio, int dato) {
    Nodo* nuevo_nodo = crear_nodo(dato);
    nuevo_nodo->siguiente = *inicio;
    if (*inicio != NULL)
        (*inicio)->anterior = nuevo_nodo;
    *inicio = nuevo_nodo;
}

// Insertar al final
void insertar_al_final(Nodo** inicio, int dato) {
    Nodo* nuevo_nodo = crear_nodo(dato);
    if (*inicio == NULL) {
        *inicio = nuevo_nodo;
        return;
    }
    Nodo* temp = *inicio;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;
    temp->siguiente = nuevo_nodo;
    nuevo_nodo->anterior = temp;
}

// Insertar en una posición específica
void insertar_en_posicion(Nodo** inicio, int dato, int posicion) {
    if (posicion < 0) {
        printf("Posición inválida\n");
        return;
    }
    if (posicion == 0) {
        insertar_al_inicio(inicio, dato);
        return;
    }
    Nodo* temp = *inicio;
    for (int i = 0; i < posicion - 1 && temp != NULL; i++)
        temp = temp->siguiente;
    if (temp == NULL) {
        printf("Posición fuera de rango\n");
        return;
    }
    Nodo* nuevo_nodo = crear_nodo(dato);
    nuevo_nodo->siguiente = temp->siguiente;
    if (temp->siguiente != NULL)
        temp->siguiente->anterior = nuevo_nodo;
    temp->siguiente = nuevo_nodo;
    nuevo_nodo->anterior = temp;
}

// Eliminar por dato
void eliminar_por_dato(Nodo** inicio, int dato) {
    Nodo* temp = *inicio;
    while (temp != NULL && temp->dato != dato)
        temp = temp->siguiente;
    if (temp == NULL) {
        printf("Dato no encontrado\n");
        return;
    }
    if (temp->anterior != NULL)
        temp->anterior->siguiente = temp->siguiente;
    else
        *inicio = temp->siguiente;
    if (temp->siguiente != NULL)
        temp->siguiente->anterior = temp->anterior;
    free(temp);
}

// Buscar por dato
Nodo* buscar_por_dato(Nodo* inicio, int dato) {
    Nodo* temp = inicio;
    while (temp != NULL) {
        if (temp->dato == dato)
            return temp;
        temp = temp->siguiente;
    }
    return NULL;
}

// Imprimir hacia adelante
void imprimir_adelante(Nodo* inicio) {
    Nodo* temp = inicio;
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

// Imprimir hacia atrás
void imprimir_atras(Nodo* inicio) {
    Nodo* temp = inicio;
    if (temp == NULL) return;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->anterior;
    }
    printf("\n");
}

// Liberar memoria
void liberar_lista(Nodo** inicio) {
    Nodo* temp = *inicio;
    while (temp != NULL) {
        Nodo* siguiente = temp->siguiente;
        free(temp);
        temp = siguiente;
    }
    *inicio = NULL;
}
