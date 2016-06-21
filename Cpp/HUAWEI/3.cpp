void scheduler(int task[], int n, int system_task[], int user_task[]) {
    int a = -1, b = -1;
    for (int i = 0; i < n; ++i) {
        if (task[i] < 50)
            system_task[++a] = task[i];
        else
            if (task[i] <= 255)
                user_task[++b] = task[i];
    }
    system_task[++a] = -1;
    user_task[++b] = -1;
}

int main(){
    return 0;
}
