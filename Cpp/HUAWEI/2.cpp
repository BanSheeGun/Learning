void sort(int input[], int n, int output[]) {
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (input[i] < input[j]) {
                int t = input[i];
                input[i] = input[j];
                input[j] = t;
            }

    int l = n / 2 + 1;
    int r = l;
    output[l] = input[0];
    for (int i = 1; i < n; ++i) {
        if (i % 2 == 1) {
            --l;
            output[l] = input[i];
        } else {
            ++r;
            output[r] = input[i];
        }
    }
}

int main(){
    return 0;
}
