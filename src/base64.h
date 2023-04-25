
#ifndef BASE64_H
#define BASE64_H

#ifdef __cplusplus
extern "C" {
#endif

//    void* GetBase64EncodeSize(const unsigned int data_in_size, unsigned int *data_out_size);
//    void* GetBase64DecodeSize(const unsigned char *data_in, const unsigned int data_in_size, unsigned int *data_out_size);
//    unsigned char GetBase64Code(const unsigned char symbol);
    void base64_encode(const unsigned char* data_in, const unsigned int data_in_size, unsigned char** LPdata_out, unsigned int *data_out_size); // encrypt in base64 binary
    void base64_decode(const unsigned char* data_in, const unsigned int data_in_size, unsigned char** LPdata_out, unsigned int *data_out_size); // decrypt in base64 binary
    char* base64_encode_str(char* data); // encrypt in base64 string
    char* base64_decode_str(char* data); // decrypt in base64 string

#ifdef __cplusplus
}
#endif

#endif /* BASE64_H */

/*
 * ================= calculating the array size for encoding ===================
 * void* GetBase64EncodeSize(const unsigned int data_in_size, unsigned int *data_out_size);
 *      data_in_size -  the size of the unencrypted message in bytes
 *      data_out_size - the size that the encrypted message will occupy
 * RETURN: allocate memory (malloc) data_out_size + 1 ('\0')
 * WARNING: do not forget to clear the memory RETURN
 * 
 * 
 * =============== calculating the size of a decoded message ===================
 * void* GetBase64DecodeSize(const unsigned char *data_in, const unsigned int data_in_size, unsigned int *data_out_size);
 *      data_in -       encrypted message
 *      data_in_size -  the size of the encrypted message
 *      data_out_size - get the size of the unencrypted message
 * RETURN: allocate memory (malloc) data_out_size + 1 ('\0')
 * WARNING: do not forget to clear the memory RETURN
 * 
 * 
 * =========== get the number of the array element by the symbol ===============
 * unsigned char GetBase64Code(const unsigned char symbol);
 *      symbol -        encrypted message character
 * RETURN: index of the symbol element in the base64_code array
 * 
 * 
 * ======================== encrypt in base64 binary ===========================
 * void base64_encode(const unsigned char* data_in, const unsigned int data_in_size, unsigned char** LPdata_out, unsigned int *data_out_size);
 *      data_in -       input byte array
 *      data_in_size -  size input byte array
 *      LPdata_out -    output encrypted array base64 (malloc)
 *      data_out_size - size output encrypted array base64 without '\0' (you can NULL)
 * RETURN: void
 * WARNING: do not forget to clear the memory LPdata_out
 * 
 * 
 * ======================== decrypt in base64 binary ===========================
 * void base64_decode(const unsigned char* data_in, const unsigned int data_in_size, unsigned char** LPdata_out, unsigned int *data_out_size);
 *      data_in -       input base64 encrypted array
 *      data_in_size -  size input base64 encrypted array
 *      LPdata_out -    output decoded array (malloc)
 *      data_out_size - size output decoded array without '\0' (you can NULL)
 * RETURN: void
 * WARNING: do not forget to clear the memory LPdata_out
 * 
 * 
 * ======================== encrypt in base64 string ===========================
 * char* base64_encode_str(char* data);
 *      data -          character string
 * RETURN: encrypted string in base64 (malloc)
 * WARNING: do not forget to clear the memory RETURN
 * 
 * 
 * ======================== encrypt in base64 string ===========================
 * char* base64_decode_str(char* data);
 *      data -          encrypted string in base64
 * RETURN: decrypt string (malloc)
 * WARNING: do not forget to clear the memory RETURN
 */