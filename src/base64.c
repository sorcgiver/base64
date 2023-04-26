
#include <stdlib.h>
#include <string.h>

#include "base64.h"

const unsigned char base64_code[65] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '+', '/',
    '='
};

void* GetBase64EncodeSize(const unsigned int data_in_size, unsigned int *data_out_size) {
    if (data_in_size % 3 != 0)
        *data_out_size = data_in_size / 3 * 4 + 4;
    else
        *data_out_size = data_in_size / 3 * 4;
    return malloc((*data_out_size) + 1);
}

void* GetBase64DecodeSize(const unsigned char *data_in, const unsigned int data_in_size, unsigned int *data_out_size) {
    int residue = data_in_size % 4;
    *data_out_size = data_in_size / 4 * 3;
    if (residue == 0) {
        if (data_in[data_in_size - 1] != base64_code[64])
            return malloc((*data_out_size) + 1);
        else if (data_in[data_in_size - 2] == base64_code[64])
            (*data_out_size) -= 2;
        else
            (*data_out_size)--;
    } else if (residue == 3)
        (*data_out_size) += 2;
    else if (residue == 2)
        (*data_out_size)++;
    else
        return NULL;
    return malloc((*data_out_size) + 1);
}

unsigned char GetBase64Code(const unsigned char symbol) {
    if (symbol >= 'A' && symbol <= 'Z')
        return symbol - 'A';
    else if (symbol >= 'a' && symbol <= 'z')
        return (symbol - 'a') + 26;
    else if (symbol >= '0' && symbol <= '9')
        return (symbol - '0') + 52;
    else if (symbol == '+')
        return 62;
    else if (symbol == '/')
        return 63;
    else
        return 64;
}

void* base64_encode(const unsigned char* data_in, const unsigned int data_in_size, unsigned int *data_out_size) {
    unsigned char* LPdata_out;
    int i, j;
    unsigned int col;
    unsigned int out_size;
    LPdata_out = GetBase64EncodeSize(data_in_size, &out_size);
    LPdata_out[out_size] = '\0';
    if (data_in_size % 3 != 0)
        col = (out_size) - 4;
    else
        col = out_size;
    for (i = 0, j = 0; i < col; i += 4, j += 3) {
        LPdata_out[i] = base64_code[data_in[j] >> 2];
        LPdata_out[i + 1] = base64_code[((data_in[j] & 0x03) << 4) | ((data_in[j + 1] & 0xf0) >> 4)];
        LPdata_out[i + 2] = base64_code[((data_in[j + 1] & 0x0f) << 2) | ((data_in[j + 2] & 0xc0) >> 6)];
        LPdata_out[i + 3] = base64_code[data_in[j + 2] & 0x3f];
    }
    if (col != out_size) {
        LPdata_out[i] = base64_code[data_in[j] >> 2];
        if (j + 1 < data_in_size) {
            LPdata_out[i + 1] = base64_code[((data_in[j] & 0x03) << 4) | ((data_in[j + 1] & 0xf0) >> 4)];
            LPdata_out[i + 2] = base64_code[((data_in[j + 1] & 0x0f) << 2)];
        } else {
            LPdata_out[i + 1] = base64_code[((data_in[j] & 0x03) << 4)];
            LPdata_out[i + 2] = base64_code[64];
        }
        LPdata_out[i + 3] = base64_code[64];
    }
    if (data_out_size != NULL)
        *data_out_size = out_size;
    return LPdata_out;
}

void* base64_decode(const unsigned char* data_in, const unsigned int data_in_size, unsigned int *data_out_size) {
    unsigned char* LPdata_out;
    int i, j, z;
    unsigned int col;
    unsigned char bc[4];
    unsigned int out_size;
    LPdata_out = GetBase64DecodeSize(data_in, data_in_size, &out_size);
    LPdata_out[out_size] = '\0';
    col = (out_size) / 3 * 3;
    for (i = 0, j = 0; i < col; i += 3, j += 4) {
        for (z = 0; z < 4; z++)
            bc[z] = GetBase64Code(data_in[j + z]);
        LPdata_out[i] = (bc[0] << 2) | (bc[1] >> 4);
        LPdata_out[i + 1] = (bc[1] << 4) | (bc[2] >> 2);
        LPdata_out[i + 2] = (bc[2] << 6) | bc[3];
    }
    if (i < out_size) {
        for (z = 0; z < 3; z++)
            bc[z] = GetBase64Code(data_in[j + z]);
        LPdata_out[i] = (bc[0] << 2) | (bc[1] >> 4);
        if (i + 1 < out_size)
            LPdata_out[i + 1] = (bc[1] << 4) | (bc[2] >> 2);
    }
    if (data_out_size != NULL)
        *data_out_size = out_size;
    return LPdata_out;
}

char* base64_encode_str(char* data) {
    return base64_encode((unsigned char*) data, strlen(data), NULL);
}

char* base64_decode_str(char* data) {
    return base64_decode((unsigned char*) data, strlen(data), NULL);
}
