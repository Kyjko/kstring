#ifndef _KSTRING
#define _KSTRING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string {
    char* m_data;
    unsigned int size;
} String;

String* create_string(const char* content);
void push(String* string, const char* newstr);
unsigned int len(String* string);
char* c_str(String* string);
void print(String* string);
void destroy(String* string);

String* create_string(const char* content) {
    String* string = (String*) malloc(sizeof(String));
    unsigned int len = strlen(content);
    string->m_data = (char*) malloc(len);
    strcpy(string->m_data, content);
    string->size = len;

    return string;
}

void push(String* string, const char* newstr) {
    unsigned int newstrlen = strlen(newstr);
    string->m_data = realloc(string->m_data, string->size + newstrlen);
    strcpy(string->m_data + string->size, newstr);
    string->size += newstrlen;
}

unsigned int len(String* string) {
    return string->size;
}

char* c_str(String* string) {
    return string->m_data;
}

void print(String* string) {
    fprintf(stdout, "%s\n", string->m_data);
}

void destroy(String* string) {
    free(string);
}

#endif
