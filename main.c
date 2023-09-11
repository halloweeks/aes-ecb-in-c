#include <stdio.h>
#include <unistd.h>
#include "aes.h"

int main() {
	uint8_t key[32];
	memset(key, 0x79, 32);
	
	// Original data
	uint8_t in[16] = "halloweeks12345";
	// Encrypted data
	uint8_t enc[16];
	// Decrypted data
	uint8_t dec[16];
	
	// print original data
	printf("Original data: ");
	for (int i = 0; i < 16; i++) {
		printf("0x%02X", in[i]);
	}
	printf("\n");
	
	// AES ECB 256 Encryption 
	AES_ecb_encrypt(in, enc, key, 256);
	
	// print encrypted data
	printf("Encrypted data: ");
	for (int i = 0; i < 16; i++) {
		printf("0x%02X", enc[i]);
	}
	printf("\n");
	
	// AES ECB 256 Decryption
	AES_ecb_decrypt(enc, dec, key, 256);
	
	// print decrypted data
	printf("Decrypted data: ");
	for (int i = 0; i < 16; i++) {
		printf("0x%02X", dec[i]);
	}
	printf("\n");
	return 0;
}