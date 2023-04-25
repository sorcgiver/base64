# base64
Simple cross-platform library written in C, for encryption/decryption in base64.
Minimal code.
A fixed array is used. The memory is computed and allocated before encoding or decoding.

encoding / decoding string
```
char* encrypt_data = base64_encode_str("encrypt string"); //encoding in base64
char* decrypt_data = base64_decode_str(encrypt_data);     //decoding from base64
free(encrypt_data);
free(decrypt_data);
```

encoding / decoding binary
```
int data[] = { 1, 2, 3, 4, 5 };
    
char* encrypt_data;
int* decrypt_data;
unsigned int encrypt_size, decrypt_size;
base64_encode((unsigned char*)data, sizeof(data), &encrypt_data, &encrypt_size);
base64_decode(encrypt_data, encrypt_size, (unsigned char*)&decrypt_data, &decrypt_size);

printf("encrypt data:\n%s\n\n", encrypt_data);
printf("decrypt data:\n");
for(int i = 0; i < decrypt_size / sizeof(int); i++){
    printf("%d ", decrypt_data[i]);
}
free(encrypt_data);
free(decrypt_data);
```
