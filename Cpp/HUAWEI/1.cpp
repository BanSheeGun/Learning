int cal_score(int score[], int judge_type[], int n) {
    int a[2], b[2];
    a[0] = 0; b[0] = 0;
    a[1] = 0; b[1] = 0;
    for (int i = 0; i < n; ++i) {
        ++b[judge_type[i] - 1];
        a[judge_type[i] - 1] += score[i];
    }
    if (b[1] == 0)
        return 1.0 * a[0] / b[0];
    else
        return 0.6 * a[0] / b[0] + 0.4 * a[1] / b[1];
}

int main(){
    return 0;
}
