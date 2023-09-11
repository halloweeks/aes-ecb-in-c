# AES ECB Encryption and Decryption

This project provides a simple implementation of AES (Advanced Encryption Standard) encryption and decryption in ECB (Electronic Codebook) mode. It supports key sizes of 128, 192, and 256 bits, with a block size of 16 bytes.

## Features

- **AES Encryption Decryption:** Supports AES-128bit, AES-192bit, and AES-256bit.
- **ECB Mode:** Implements the Electronic Codebook mode, which encrypts each block of data independently.
  
## Usage

1. Clone the repository to your local machine:

   ```shell
   git clone https://github.com/halloweeks/aes-ecb-in-c.git
   ```

2. Compile the code using your preferred C compiler:

   ```shell
   gcc main.c -o main.exe
   ```

3. Run the program:

   ```shell
   ./main.exe
   ```

## Example AES 256
```
#include <stdio.h>
#include <stdint.h>
#include "aes.h"

int main() {
    // Define your 16-byte plaintext and key
    uint8_t plaintext[16] = "Hello, AES ECB!";
    uint8_t key[32] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F
    };

    // Create an array for the ciphertext (16 bytes)
    uint8_t ciphertext[16];

    // Encrypt the plaintext
    AES_ecb_encrypt(plaintext, ciphertext, key, 256);

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < 16; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    AES_ecb_decrypt(ciphertext, plaintext, key, 256);

    // Print the decrypted plaintext
    printf("Decrypted: %s\n", plaintext);

    return 0;
}
```

## Supported Key Sizes

- AES-128 (128-bit key)
- AES-192 (192-bit key)
- AES-256 (256-bit key)

## Acknowledgments

- AES block size is 16 bytes, meaning the maximum data size for a single block of encryption or decryption is 16 bytes (128 bits).
- To encrypt or decrypt data larger than 16 bytes, you should divide it into 16-byte blocks and process each block independently. 

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
