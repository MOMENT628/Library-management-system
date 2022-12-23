#pragma once
//转换字符数组为16进制数
int toUnicode(const char* str)
{
	return str[0] + (str[1] ? toUnicode(str + 1) : 0);
}

constexpr inline int U(const char* str)
{
	return str[0] + (str[1] ? U(str + 1) : 0);
}