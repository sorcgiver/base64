# base64
Simple cross-platform library written in C, for encryption/decryption in base64.
Minimal code.
A fixed array is used. The memory is computed and allocated before encoding or decoding.

encoding / decoding string
```
char* encrypt_data = base64_encode_str("encrypt string"); //encoding in base64
char* decrypt_data = base64_decode_str(encrypt_data);     //decoding from base64
```
