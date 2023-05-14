#include <stdio.h>

// Calculates the parity bit for a given data bit
int calculate_parity(int data[], int size, int parity_pos) {
    int parity = 0;
    for (int i = parity_pos - 1; i < size; i += 2 * parity_pos) {
        for (int j = i; j < i + parity_pos && j < size; j++) {
            parity ^= data[j];
        }
    }
    return parity;
}

int main() {
    // Example data to be encoded
    int data[8] = {1, 0, 1, 0,1,0,1,1,};
    int size = 8;
    
    // Calculate number of parity bits required
    int parity_bits = 0;
    while (size + parity_bits + 1 > (1 << parity_bits)) {
        parity_bits++;
    }
    
    // Allocate memory for encoded data
    int encoded[size + parity_bits];
    
    // Insert data bits into encoded data
    int k = 0;
    for (int i = 0; i < size + parity_bits; i++) {
        if ((i & (i + 1)) == 0) { // if i+1 is a power of 2
            encoded[i] = 0; // set parity bit to 0
        } else {
            encoded[i] = data[k++]; // insert data bit
        }
    }
    
    // Calculate parity bits and insert them into encoded data
    for (int i = 0; i < parity_bits; i++) {
        int parity_pos = (1 << i);
        encoded[parity_pos - 1] = calculate_parity(encoded, size + parity_bits, parity_pos);
    }
    
    // Print encoded data
    printf("Encoded data: ");
    for (int i = 0; i < size + parity_bits; i++) {
        printf("%d", encoded[i]);
    }
    printf("\n");
    
    return 0;
}
