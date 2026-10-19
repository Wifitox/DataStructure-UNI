#include <iostream> // Para poder usar cin y cout (entrada y salida)
#include <vector>   // Para poder usar la estructura de datos vector

using namespace std; // Para no tener que escribir std:: antes de cada cosa

// -----------------------------------------------------------
// Función partition (partición): reordena el segmento [inicio, fin]
// eligiendo un "pivote" y colocando a su izquierda todo lo menor o
// igual que él, y a su derecha todo lo mayor.
// Regresa el índice final donde quedó ubicado el pivote.
// v: vector original (se modifica in place, por eso es &)
// inicio: índice donde comienza el segmento a particionar
// fin: índice donde termina el segmento (aquí se toma el pivote)
// -----------------------------------------------------------
template <typename T>
int partition(vector<T>& v, int inicio, int fin) {
    T pivote = v[fin];
    int i = inicio - 1;


    for (int j = inicio; j < fin; j++) {


        if (v[j] <= pivote) {
            i++;              
            swap(v[i], v[j]); 
        }
    }

   
    swap(v[i + 1], v[fin]);

   
    return i + 1;
}

// -----------------------------------------------------------
// Función quickSort: ordena el segmento [inicio, fin] del vector
// usando la estrategia de dividir y conquistar
// v: vector a ordenar
// inicio: índice inicial del segmento a ordenar
// fin: índice final del segmento a ordenar
// -----------------------------------------------------------
template <typename T>
void quickSort(vector<T>& v, int inicio, int fin) {

    
    if (inicio >= fin) {
        return; 
    }

    int posPivote = partition(v, inicio, fin);

    
    quickSort(v, inicio, posPivote - 1);

    quickSort(v, posPivote + 1, fin);
}

// -----------------------------------------------------------
// Función auxiliar para imprimir el vector en pantalla
// -----------------------------------------------------------
template <typename T>
void imprimir(const vector<T>& v) {
    for (const T& num : v) {        // recorremos cada elemento del vector
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

    // Llamamos a quickSort indicando el rango completo del vector:
    // desde el índice 0 hasta el último índice (datos.size() - 1)
    quickSort(datos, 0, datos.size() - 1);

    cout << "Vector ordenado: ";
    imprimir(datos); // mostramos el vector después de ordenar

    return 0; // el programa terminó correctamente
}