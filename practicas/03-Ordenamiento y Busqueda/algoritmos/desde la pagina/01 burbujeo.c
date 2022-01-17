void bubble_sort(int* vector)
{
    int iteración = 0;
    bool permutation = true;
    int actual;
   
    while ( permutation) {
        permutation = false;
        iteración ++;
        for (actual=0;actual<20-iteración;actual++) {
            if (vector[actual]>vector[actual+1]){
                permutation = true;
                // Intercambiamos los dos elementos
                int temp = vector[actual];
                vector[actual] = vector[actual+1];
                vector[actual+1] = temp;
            }
        }
    }
}