#pragma once
//ת���ַ�����Ϊ16������
int toUnicode(const char* str)
{
	return str[0] + (str[1] ? toUnicode(str + 1) : 0);
}

constexpr inline int U(const char* str)
{
	return str[0] + (str[1] ? U(str + 1) : 0);
}