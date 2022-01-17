void quick_sort (int *vector, int tamano) {
    int pared, actual, pivote, tmp;
    if (tamano < 2) return;
    // el elemento de pivote es la más a la derecha
    pivote = vector[tamano - 1];
    pared  = actual = 0;
    while (actual<tamano) {
        if (vector[actual] <= pivote) {
            if (pared != actual) {
                tmp=vector[actual];
                vector[actual]=vector[pared];
                vector[pared]=tmp;              
            }
            pared ++;
        }
        actual ++;
    }
    quick_sort(vector, pared - 1);
    quick_sort(vector + pared - 1, tamano - pared + 1);
}