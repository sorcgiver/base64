
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base64.h"

/*
 * 
 */
int main(int argc, char** argv) {
    char* data = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.";
    unsigned char* encrypt_data;
    unsigned char* decrypt_data;
    encrypt_data = base64_encode_str(data);
    decrypt_data = base64_decode_str(encrypt_data);
    printf("encrypt data:\n%s\n\n", encrypt_data);
    printf("decrypt data:\n%s\n\n", decrypt_data);
    free(encrypt_data);
    free(decrypt_data);
    return 0;
}

/*
//=================== simple encoding decoding string ==========================
int main(int argc, char** argv) {
    char* data = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.";
    unsigned char* encrypt_data;
    unsigned char* decrypt_data;
    encrypt_data = base64_encode_str(data);
    decrypt_data = base64_decode_str(encrypt_data);
    printf("encrypt data:\n%s\n\n", encrypt_data);
    printf("decrypt data:\n%s\n\n", decrypt_data);
    free(encrypt_data);
    free(decrypt_data);
    return 0;
}
 * 
 * 
 * 
 * 
//==================== encrypting and decrypting binary data====================
int main(int argc, char** argv) {
    int data[] = {
        10, 11, 12, 13, 14, 15,
        21, 432, 4343, 80321, 1234521
    };
    unsigned int data_size = sizeof(data);
    
    unsigned char* encrypt_data;
    int* decrypt_data;
    unsigned int encrypt_size, decrypt_size, decrypt_int_size;
    base64_encode((unsigned char*)data, data_size, &encrypt_data, &encrypt_size);
    base64_decode(encrypt_data, encrypt_size, (unsigned char*)&decrypt_data, &decrypt_size);
    decrypt_int_size = decrypt_size / sizeof(int);
    
    printf("encrypt size: %u\nencrypt data:\n%s\n\n", encrypt_size, encrypt_data);

    printf("decrypt size: %u\ndecrypt data:\n", decrypt_int_size);
    for(int i = 0; i < decrypt_int_size; i++){
        printf("%d ", decrypt_data[i]);
    }
    printf("\n\n");
    free(encrypt_data);
    free(decrypt_data);
    return 0;
}
 */