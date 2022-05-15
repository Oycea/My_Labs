#ifndef _ENCODING_FUNC_H_
#define _ENCODING_FUNC_H_

//���� ������ (����������� ����� �������� ����� �� 3 �������)
char Caesars_cipher(char letter);

//���������� �� ����� ������
char Caesars_decipher(char letter);

//�������� �����
void crypt(FILE* original_text, FILE* encrypted_text);

//���������� �����
void decrypt(FILE* encrypted_text, FILE* decrypted_text);

//�������� ������������ ������������� � �������������� �������
bool is_identity(FILE* original_text, FILE* decrypted_text);

#endif //_ENCODING_FUNC_H_
