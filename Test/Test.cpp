// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <atlstr.h>
#include <fileapi.h>
#include<cstring>
#include<stdio.h>

void false_positive_9040();
void false_positive_2173();
void true_positive_sample(char* test);
void false_positive_8633(CString, CString);
void test_format(char const* const format, ...);
void fp_8586();
int main(int argv , char ** args ) {
    if (argv > 2) {
        //test_format(args[1], args[2]);
        false_positive_8633(CString(args[1]), CString(args[2]));
    }
    /*if (argv > 1) {
        true_positive_sample(args[1]);
    }
    fp_8586();
    false_positive_9040();
    false_positive_2173();
    return 0;*/
}
void true_positive_sample(char * test) {
    char buf[10];
    memcpy(buf, test, 15);
}
void false_positive_9040() {
    CString csTempPath;
    GetTempPath(_MAX_PATH, csTempPath.GetBuffer(_MAX_PATH));
    csTempPath.ReleaseBuffer();
}
void false_positive_2173() {
   HANDLE cp = GetCurrentProcess();
   TerminateProcess(cp, 0);
}
void false_positive_8633(CString test , CString test2) {
    CString sProfileName;

    //VS_FIXEDFILEINFO fixedInfo;
    //CStringW sTemp;
    //HANDLE test = CreateFile((LPCWSTR)"test.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    //sTemp.LoadString(test, )
    int (*test123)(wchar_t* const _Buffer, size_t const _BufferCount, wchar_t const* const _Format, va_list _ArgList) = vswprintf_s;
    int (*test456)(wchar_t*, unsigned __int64, const wchar_t*, char*) = ChTraitsCRT<wchar_t>::Format;

    char target[256];
    //test_format(target, 256, (char*) test.GetBuffer(), test2);

    sProfileName.Format(test, _T("dfdfdfdf"), test2 );
}
void test_format(char const* const format, ...)
{
    va_list args;
    int len;
    char* buffer;

    va_start(args, format);
    len = _vscprintf(format, args) // _vscprintf doesn't count
        + 1; // terminating '\0'
    buffer = (char*)malloc(len * sizeof(char));
    if (NULL != buffer)
    {
        ChTraitsCRT<wchar_t>::Format((LPWSTR)buffer, len, (LPCWSTR)format, args);
        puts(buffer);
        free(buffer);
    }
    va_end(args);
}
void fp_8586() {
    TCHAR szTempPath[MAX_PATH] = { 0 };
    TCHAR szTempFile[MAX_PATH] = { 0 };
    bool res = (GetTempPath(MAX_PATH, szTempPath) && GetTempFileName(szTempPath, _T("Flt"), 0, szTempFile));
    if (res) {
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file