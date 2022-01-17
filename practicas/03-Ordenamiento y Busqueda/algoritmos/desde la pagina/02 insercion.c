void Insertion_sort(int* t)
{
    int i, j;
    int actual;
 
    for (i = 1; i < 20; i++) {
        actual = t[i];
        for (j = i; j > 0 && t[j - 1] > actual; j--) {
            t[j] = t[j - 1];
        }
        t[j] = actual;
    }
}