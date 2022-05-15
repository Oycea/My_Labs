#ifndef _DECRYPT_H_
#define _DECRYPT_H_

//Дешифровка по шифру Цезаря
char Caesars_decipher(char letter, int k);

//Дешифровка шифра по порядку букв на клавиатуре (сдвиг влево)
char keyboard_decipher(char letter);

//Дешифровка файла с шифром Цезаря
void decrypt_Caesars_decipher(FILE* encrypted_text, FILE* decrypted_text, int k);

//Дешифровка файла со сдвигом букв на клавиатуре
void decrypt_keyboard_decipher(FILE* encrypted_text, FILE* decrypted_text);

#endif //_DECRYPT_H_
