#ifndef _DECRYPT_H_
#define _DECRYPT_H_

//���������� �� ����� ������
char Caesars_decipher(char letter, int k);

//���������� ����� �� ������� ���� �� ���������� (����� �����)
char keyboard_decipher(char letter);

//���������� ����� � ������ ������
void decrypt_Caesars_decipher(FILE* encrypted_text, FILE* decrypted_text, int k);

//���������� ����� �� ������� ���� �� ����������
void decrypt_keyboard_decipher(FILE* encrypted_text, FILE* decrypted_text);

#endif //_DECRYPTH_