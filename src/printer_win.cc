#include "printer_win.h"
#include <iostream>

namespace node_pdfium
{
Unique_HDC GetPrinterDC(const v8::Local<v8::Value> &printerName)
{
    const v8::Local<v8::String> printerNameV8Str = printerName->ToString(Nan::GetCurrentContext()).ToLocalChecked();

    Unique_HDC printerDC(::CreateDCW(L"WINSPOOL", reinterpret_cast<LPCWSTR>(*v8::String::Value(v8::Isolate::GetCurrent(), printerNameV8Str)), NULL, NULL));

    return printerDC;
}
Unique_HPrinter GetPrinterHanlde(const v8::Local<v8::Value> &printerName)
{
    const v8::Local<v8::String> printerNameV8Str = printerName->ToString(Nan::GetCurrentContext()).ToLocalChecked();

    HANDLE handle = NULL;

    ::OpenPrinterW(reinterpret_cast<LPWSTR>(*v8::String::Value(v8::Isolate::GetCurrent(), printerNameV8Str)), &handle, NULL);

    Unique_HPrinter printerH(handle);

    return printerH;
}
} // namespace node_pdfium