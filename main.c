#include <stdio.h>
#include "double_list.h"

int main() {
    Nodo* lista = NULL;

    // Insertar nodos
    insertar_al_inicio(&lista, 10);
    insertar_al_final(&lista, 20);
    insertar_en_posicion(&lista, 15, 1); // Insertar en posición 1
    insertar_en_posicion(&lista, 25, 3); // Insertar en posición 3

    printf("Lista hacia adelante:\n");
    imprimir_adelante(lista);

    printf("Lista hacia atrás:\n");
    imprimir_atras(lista);

    // Buscar un elemento
    Nodo* encontrado = buscar_por_dato(lista, 15);
    if (encontrado)
        printf("Elemento encontrado: %d\n", encontrado->dato);
    else
        printf("Elemento no encontrado\n");

    // Eliminar un elemento
    eliminar_por_dato(&lista, 15);
    printf("Lista después de eliminar 15:\n");
    imprimir_adelante(lista);

    // Liberar memoria
    liberar_lista(&lista);

    return 0;
}
