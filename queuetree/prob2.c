int max_consecutive_gates(char* gates) {
    int n = strlen(gates);
    if (n == 0) return 0;
    
    int max_length = 0;
    int current_length = 0;
    int balance = 0;
    
    for (int i = 0; i < n; i++) {
        if (gates[i] == '(') {
            balance++;
            current_length++;
        } else if (gates[i] == ')') {
            if (balance > 0) {
                balance--;
                current_length++;
                if (balance == 0) {
                    if (current_length > max_length) {
                        max_length = current_length;
                    }
                }
            } else {
                current_length = 0;
                balance = 0;
            }
        }
    }
    
    return max_length;
}

int main() {
    char gates[MAX_SIZE];
    scanf("%s", gates);
    
    int result = max_consecutive_gates(gates);
    printf("%d\n", result);
    
    return 0;
}