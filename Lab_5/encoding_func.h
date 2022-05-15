#ifndef _ENCODING_FUNC_H_
#define _ENCODING_FUNC_H_

//Шифр Цезаря (циклический сдвиг алфавита влево на 3 позиции)
char Caesars_cipher(char letter);

//Дешифровка по шифру Цезаря
char Caesars_decipher(char letter);

//Шифровка файла
void crypt(FILE* original_text, FILE* encrypted_text);

//Дешифровка файла
void decrypt(FILE* encrypted_text, FILE* decrypted_text);

//Проверка идентичности оригинального и дешифрованного текстов
bool is_identity(FILE* original_text, FILE* decrypted_text);

#endif //_ENCODING_FUNC_H_
