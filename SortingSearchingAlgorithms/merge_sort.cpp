#include <iostream> 
#include <vector>   

using namespace std; 

// -----------------------------------------------------------
// Función merge: combina dos sub-vectores YA ORDENADOS en uno solo
// v: vector original (sobre el que trabajamos)
// inicio: índice donde comienza el primer sub-vector
// medio: índice donde termina el primer sub-vector (y empieza el segundo)
// fin: índice donde termina el segundo sub-vector
// -----------------------------------------------------------
void merge(vector<int>& v, int inicio, int medio, int fin) {

    // Calculamos el tamaño del sub-vector izquierdo
    int tamIzq = medio - inicio + 1;
    // Calculamos el tamaño del sub-vector derecho
    int tamDer = fin - medio;

    // Creamos vectores temporales para guardar copias de cada mitad
    vector<int> izquierda(tamIzq);
    vector<int> derecha(tamDer);

    // Copiamos los elementos de v al vector "izquierda"
    for (int i = 0; i < tamIzq; i++) {
        izquierda[i] = v[inicio + i]; // desplazamos el índice según "inicio"
    }

    // Copiamos los elementos de v al vector "derecha"
    for (int j = 0; j < tamDer; j++) {
        derecha[j] = v[medio + 1 + j]; // empezamos justo después de "medio"
    }

    // i recorre el vector izquierda, j recorre el vector derecha
    int i = 0;
    int j = 0;
    // k recorre el vector original v, donde vamos a ir colocando los valores ordenados
    int k = inicio;

    // Mientras haya elementos sin comparar en ambos sub-vectores...
    while (i < tamIzq && j < tamDer) {
        // Comparamos el elemento actual de cada mitad
        if (izquierda[i] <= derecha[j]) {
            v[k] = izquierda[i]; // si el de la izquierda es menor o igual, va primero
            i++;                 // avanzamos en el sub-vector izquierdo
        } else {
            v[k] = derecha[j];   // si no, el de la derecha va primero
            j++;                 // avanzamos en el sub-vector derecho
        }
        k++; // en cualquier caso, avanzamos en el vector original
    }

    // Si sobraron elementos en "izquierda" (porque "derecha" se acabó primero),
    // los copiamos tal cual, ya que estaban ordenados entre sí
    while (i < tamIzq) {
        v[k] = izquierda[i];
        i++;
        k++;
    }

    // Si sobraron elementos en "derecha", hacemos lo mismo
    while (j < tamDer) {
        v[k] = derecha[j];
        j++;
        k++;
    }
}

// -----------------------------------------------------------
// Función mergeSort: divide el vector recursivamente hasta
// llegar a sub-vectores de un solo elemento, y luego los va
// combinando (mergeando) de forma ordenada
// v: vector a ordenar
// inicio: índice inicial del segmento a ordenar
// fin: índice final del segmento a ordenar
// -----------------------------------------------------------
void mergeSort(vector<int>& v, int inicio, int fin) {

    // Caso base: si inicio >= fin, el segmento tiene 0 o 1 elementos
    // y por lo tanto ya está "ordenado" (no hay nada que hacer)
    if (inicio >= fin) {
        return; // salimos de la función, terminó la recursión en esta rama
    }

    // Calculamos el punto medio del segmento actual
    // Se usa inicio + (fin - inicio) / 2 en vez de (inicio + fin) / 2
    // para evitar problemas de overflow con números muy grandes
    int medio = inicio + (fin - inicio) / 2;

    // Ordenamos recursivamente la mitad izquierda [inicio, medio]
    mergeSort(v, inicio, medio);

    // Ordenamos recursivamente la mitad derecha [medio+1, fin]
    mergeSort(v, medio + 1, fin);

    // Una vez que ambas mitades están ordenadas, las combinamos
    merge(v, inicio, medio, fin);
}

// -----------------------------------------------------------
// Función auxiliar para imprimir el vector en pantalla
// -----------------------------------------------------------
void imprimir(const vector<int>& v) {
    for (int num : v) {        // recorremos cada elemento del vector
        cout << num << " ";    // lo imprimimos seguido de un espacio
    }
    cout << endl; // salto de línea al final
}

// -----------------------------------------------------------
// Función principal
// -----------------------------------------------------------
int main() {

    // Vector de ejemplo sin ordenar
    vector<int> datos = {38, 27, 43, 3, 9, 82, 10};

    cout << "Vector original: ";
    imprimir(datos); // mostramos el vector antes de ordenar

    // Llamamos a mergeSort indicando el rango completo del vector:
    // desde el índice 0 hasta el último índice (datos.size() - 1)
    mergeSort(datos, 0, datos.size() - 1);

    cout << "Vector ordenado: ";
    imprimir(datos); // mostramos el vector después de ordenar

    return 0; // el programa terminó correctamente
}